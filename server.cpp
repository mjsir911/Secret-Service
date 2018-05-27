#include <QtDBus/QtDBus>

#include "SecretAdaptor.h"
#include "SecretInterface.h"

#include <iostream>

#include "Secret.h"

#include <QDBusMetaType>

int main(int ac, char **av) {
	qDBusRegisterMetaType<StringMap>(); // FINALLY

	QCoreApplication a(ac, av);

	QDBusConnection dbus = QDBusConnection::sessionBus();

	SecretService secret(&a);
	ServiceAdaptor adaptor(&secret);

	OrgFreedesktopSecretServiceInterface interface("org.freedesktop.Secret.Service", "org/freedesktop/secrets", dbus, &secret);

	dbus.registerService("org.freedesktop.Secret.Service");
	dbus.registerService("org.freedesktop.secrets");
	dbus.registerObject("/org/freedesktop/secrets", &secret);

	a.exec();

}
