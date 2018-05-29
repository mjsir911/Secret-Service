#ifndef ITEM_H
#define ITEM_H

#include <QtDBus/QtDBus>
#include "Types.h"

#include "Session.h"

class _Item : public QObject, public QDBusContext{
	Q_OBJECT

private:
	QDBusConnection &bus;

public:
	const QDBusObjectPath path;
	const QString interface = "org.freedesktop.Secret.Item";
	_Item(QObject *, QDBusConnection &, QDBusObjectPath);
	~_Item();

public Q_SLOTS: // METHODS
    QDBusObjectPath Delete();
    SecretStruct GetSecret(const QDBusObjectPath &session);
    void SetSecret(SecretStruct secret);
Q_SIGNALS: // SIGNALS
};
#endif
