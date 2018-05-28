#include <QtDBus/QtDBus>
#include <QThread>

#include "Prompt.h"
#include "PromptAdaptor.h"
#include "PromptInterface.h"


#include "Utils.h"

_Prompt::_Prompt(QObject *parent, QDBusConnection &bus, QList<QDBusObjectPath> objectPaths) : QObject(parent), bus(bus), path(_Prompt::generatePath()), objectPaths(objectPaths) {
	debugline();
	new PromptAdaptor(this);
	new OrgFreedesktopSecretPromptInterface(interface, path.path(), bus, this);

	bus.registerService(interface);
	bus.registerObject(path.path(), this);
}
_Prompt::~_Prompt() {
	bus.unregisterObject(path.path());
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
	QThread::usleep(1); // Holy shit why is this needed
	delete this;
}
