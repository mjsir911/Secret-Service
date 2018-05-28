.SUFFIXES:
CXXFLAGS := $(shell pkg-config Qt5DBus libsodium --cflags) -fPIC
LDFLAGS  := $(shell pkg-config Qt5DBus libsodium --libs)

SERVICE = org.freedesktop.Secret
INTERFACES = Service Collection Item Session Prompt
 
.PRECIOUS: %.o

%Interface.cpp %Interface.h: $(SERVICE)s.xml %.h
	qdbusxml2cpp $< -i $*.h -l $* -p $*Interface $(SERVICE).$*

%Adaptor.cpp %Adaptor.h: %.h $(SERVICE)s.xml
	qdbusxml2cpp -i $^ -l _$* -a $*Adaptor $(SERVICE).$*

%.moc: %.h %.cpp # For some reason the order here determines an interemediate file being removed. Ah well, better cpp get removed than .h
	moc -f $< -f $(word 2,$^) $(DEFINES) $(INCPATH) $< -o $@

%.o: %.moc
	$(COMPILE.cpp) -xc++ $(OUTPUT_OPTION) $<

%.dbus.o: %.o %Adaptor.o %Interface.o
	$(LD) $(OUTPUT_OPTION) -r $^ 

clean:
	${RM} *.moc *Adaptor* *Interface* *.o
