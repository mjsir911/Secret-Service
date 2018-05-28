#include <QtDBus/QtDBus>

#include "Types.h"

#include <iostream>

#include "Service.h"

#include <QDBusMetaType>

#include <sodium.h>

int main(int ac, char **av) {
	sodium_init();
	registerMetaTypes();


	QCoreApplication a(ac, av);

	QDBusConnection dbus = QDBusConnection::sessionBus();

	_Service secret(&a, dbus);

	a.exec();

}
