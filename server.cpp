#include <QtDBus/QtDBus>

#include "SecretAdaptor.h"
#include "SecretInterface.h"

#include <iostream>

/*
int main(int ac, char **av) {
	QCoreApplication a(ac, av);

  Calc c(&a);



	QDBusConnection dbus = QDBusConnection::sessionBus();
	dbus.registerService("org.freedesktop.secrets");
	dbus.registerObject("/org/freedesktop/secrets", &c);

  return a.exec();

}
*/

#include "Secret.h"

int main(int ac, char **av) {

	QCoreApplication a(ac, av);

	QDBusConnection dbus = QDBusConnection::sessionBus();

	SecretService secret(&a);
	ServiceAdaptor adaptor(&secret);

	OrgFreedesktopSecretServiceInterface interface("org.freedesktop.secrets", "org/freedesktop/secrets", dbus, &secret);

	dbus.registerService("org.freedesktop.secrets");
	dbus.registerObject("/org/freedesktop/secrets", &secret);

	a.exec();

}
