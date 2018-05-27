CXXFLAGS := $(shell pkg-config Qt5DBus --cflags) -fPIC
LDFLAGS  := $(shell pkg-config Qt5DBus --libs)

TARGET = server

$(TARGET): SecretAdaptor.o moc_SecretAdaptor.o SecretInterface.o moc_SecretInterface.o server.o Secret.o
	$(LINK.cc) $(OUTPUT_OPTION) $^

run: $(TARGET)
	./$<

moc_%.cpp: %.h
	moc $(DEFINES) $(INCPATH) $< -o $@

%Adaptor.cpp %Adaptor.h: %.xml
	qdbusxml2cpp $< -i Secret.h -l SecretService -a $*Adaptor

%Interface.cpp %Interface.h: %.xml
	qdbusxml2cpp $< -i Secret.h -l SecretService -p $*Interface

clean:
	${RM} moc_* *Adaptor* *Interface* {moc_,}Secret{A,I}* *.o
