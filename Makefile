# .SUFFIXES:

CXXFLAGS := $(shell pkg-config Qt5DBus libsodium --cflags) -fPIC
LDFLAGS  := $(shell pkg-config Qt5DBus libsodium --libs)

TARGET = server

$(TARGET): SecretAdaptor.moc SecretInterface.moc server.o Secret.moc Types.o
	$(LINK.cc) $(OUTPUT_OPTION) $^

run: $(TARGET)
	./$<

%.moc: %.moc.cpp
	$(COMPILE.cpp) -xc++ $(OUTPUT_OPTION) $<


%.moc.cpp: %.h %.cpp
	moc -f $*.cpp $(DEFINES) $(INCPATH) $< -o $@

%.cpp: %.h

%.o:  %.cpp
	$(COMPILE.cpp) $(OUTPUT_OPTION) $<

%Adaptor.cpp %Adaptor.h: %.xml
	qdbusxml2cpp $< -i Secret.h -l SecretService -a $*Adaptor

%Interface.cpp %Interface.h: %.xml
	qdbusxml2cpp $< -i Secret.h -l SecretService -p $*Interface

clean:
	${RM} *.moc *Adaptor* *Interface* *.o
