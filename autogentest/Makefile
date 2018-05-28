.SUFFIXES:
CXXFLAGS := $(shell pkg-config Qt5DBus libsodium --cflags) -fPIC
LDFLAGS  := $(shell pkg-config Qt5DBus libsodium --libs)

SERVICE = org.freedesktop.Secret
INTERFACES = Service Collection Item Session Prompt
 
.PRECIOUS: %.o


TARGET = server

$(TARGET): Service.dbus.o main.cpp Types.cpp Prompt.dbus.o
	g++ $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

%Interface.cpp %Interface.h: %.h $(SERVICE)s.xml
	qdbusxml2cpp $(word 2,$^) -i $< -l _$* -p $*Interface $(SERVICE).$*

%Adaptor.cpp %Adaptor.h: %.h $(SERVICE)s.xml
	qdbusxml2cpp $(word 2,$^) -i $< -l _$* -a $*Adaptor $(SERVICE).$*

%.moc: %.cpp %.h # For some reason the order here determines an interemediate file being removed. Ah well, better cpp get removed than .h
	moc -f $(word 1,$^) $(DEFINES) $(INCPATH) $(word 2,$^) -o $@

%.o: %.moc
	$(COMPILE.cpp) -xc++ $(OUTPUT_OPTION) $<

# %.o: %.cpp
	# $(COMPILE.cpp) $(OUTPUT_OPTION) $<

%.dbus.o: %.o %Adaptor.o %Interface.o
	$(LD) $(OUTPUT_OPTION) -r $^ 

clean:
	${RM} *.moc *Adaptor* *Interface* *.o
