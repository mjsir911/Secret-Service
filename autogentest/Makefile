%Adaptor.cpp %Adaptor.h: org.freedesktop.Secrets.xml %.h
	qdbusxml2cpp $< -i $*.h -l $* -a $*Adaptor

%Interface.cpp %Interface.h: org.freedesktop.Secrets.xml %.h
	qdbusxml2cpp $< -i $*.h -l $* -p $*Interface org.freedesktop.Secret.$*
