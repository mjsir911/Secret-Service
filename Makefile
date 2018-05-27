# .SUFFIXES:

CXXFLAGS := $(shell pkg-config Qt5DBus --cflags) -fPIC
LDFLAGS  := $(shell pkg-config Qt5DBus --libs) -l cryptopp

TARGET = server

$(TARGET): SecretAdaptor.o SecretInterface.o server.o Secret.o
	$(LINK.cc) $(OUTPUT_OPTION) $^

run: $(TARGET)
	./$<

%.o: %.moc %.h
	$(COMPILE.cpp) -xc++ $(OUTPUT_OPTION) $<


%.moc: %.h %.cpp
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
