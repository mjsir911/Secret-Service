#include <QtDBus/QtDBus>

#include "Types.h"

#include <iostream>

#include "Service.h"

#include "Prompt.h"

#include <QDBusMetaType>

#include <sodium.h>

int main(int ac, char **av) {
	if (sodium_init() < 0) {
		throw;
	}
	registerMetaTypes();


	QCoreApplication a(ac, av);

	QDBusConnection dbus = QDBusConnection::sessionBus();
	dbus.registerService("org.freedesktop.secrets");

	_Service secret(&a, dbus);

	_Prompt hi(&a, dbus);

	a.exec();

}
