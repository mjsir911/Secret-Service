#ifndef SERVICE_H
#define SERVICE_H

#include <QtDBus/QtDBus>

#include "Types.h"

#include "Item.h"

class _Service : public QObject, public QDBusContext {
	Q_OBJECT

friend class Item;
private:
	QDBusObjectPath generatePath(void);
	QDBusConnection &bus;

public:
	QMap<QDBusObjectPath, QByteArray> encryptionDict;

public:
	const QDBusObjectPath path = QDBusObjectPath("/org/freedesktop/secrets");
	const QString interface = "org.freedesktop.Secret.Service";
	_Service(QObject *, QDBusConnection &);

public Q_SLOTS: // METHODS
    QDBusObjectPath ChangeLock(const QDBusObjectPath &collection);
    QDBusObjectPath CreateCollection(CollectionSpecifier properties, const QString &alias, QDBusObjectPath &prompt);
    SecretsDict GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session);
    QList<QDBusObjectPath> Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt);
    void LockService();
    QDBusVariant OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &result);
    QDBusObjectPath ReadAlias(const QString &name);
    QList<QDBusObjectPath> SearchItems(StringMap attributes, QList<QDBusObjectPath> &locked);
    void SetAlias(const QString &name, const QDBusObjectPath &collection);
    QList<QDBusObjectPath> Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt);
Q_SIGNALS: // SIGNALS
    void CollectionChanged(const QDBusObjectPath &collection);
    void CollectionCreated(const QDBusObjectPath &collection);
    void CollectionDeleted(const QDBusObjectPath &collection);
};
#endif
