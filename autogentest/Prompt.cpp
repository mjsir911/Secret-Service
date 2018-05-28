#include <QtDBus/QtDBus>

#include "Prompt.h"
#include "PromptAdaptor.h"
#include "PromptInterface.h"

QString GetRandomString(const int randomStringLength) { // https://stackoverflow.com/a/18866593/6381767
   const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = qrand() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

#include "Utils.h"

_Prompt::_Prompt(QObject *parent, QDBusConnection &bus, QList<QDBusObjectPath> objectPaths) : QObject(parent), path(_Prompt::generatePath()), objectPaths(objectPaths) {
	debugline();
	new PromptAdaptor(this);
	new OrgFreedesktopSecretPromptInterface(interface, path.path(), bus, this);

	bus.registerObject(path.path(), this);
}

QDBusObjectPath _Prompt::generatePath(void) {
	return QDBusObjectPath("/org/freedesktop/secrets/prompts/" + GetRandomString(12));
}


void _Prompt::Dismiss() {
	debugline();
	throw NotImplementedException();
	delete this;
}

void _Prompt::Prompt(const QString &window_id) {
	debugline();
	// TODO: prompt master password
	QVariant b = QVariant::fromValue(objectPaths);
	qDebug() << "window_id: " << window_id;
	emit Completed(true, QDBusVariant(b));
	delete this;
}
