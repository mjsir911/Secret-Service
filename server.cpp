#include <QtDBus/QtDBus>

#include "SecretAdaptor.h"
#include "SecretInterface.h"

#include <iostream>

#include "Secret.h"

#include <QDBusMetaType>

#include <sodium.h>

int main(int ac, char **av) {
	sodium_init();

	qDBusRegisterMetaType<StringMap>(); // FINALLY
	qDBusRegisterMetaType<SecretsDict>(); // FINALLY
	qDBusRegisterMetaType<Secret>(); // FINALLY

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
