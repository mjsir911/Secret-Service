#include <QtDBus/QtDBus>
#include "Types.h"

class _Service : public QObject, public QDBusContext{
	Q_OBJECT

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
