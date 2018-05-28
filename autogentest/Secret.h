#include "Types.h"

class Secret : public QObject, public QDBusContext{
	Q_OBJECT

// SERVICE
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

//COLLECTION
public Q_SLOTS: // METHODS
    QDBusObjectPath CreateItem(CollectionSpecifier properties, SecretStruct secret, bool replace, QDBusObjectPath &prompt);
    QDBusObjectPath Delete();
    QList<QDBusObjectPath> SearchItems(StringMap attributes);
Q_SIGNALS: // SIGNALS
    void ItemChanged(const QDBusObjectPath &item);
    void ItemCreated(const QDBusObjectPath &item);
    void ItemDeleted(const QDBusObjectPath &item);

//ITEM
public Q_SLOTS: // METHODS
    QDBusObjectPath Delete();
    SecretStruct GetSecret(const QDBusObjectPath &session);
    void SetSecret(SecretStruct secret);
Q_SIGNALS: // SIGNALS

//SESSION
public Q_SLOTS: // METHODS
    void Close();
Q_SIGNALS: // SIGNALS

//PROMPT
public Q_SLOTS: // METHODS
    void Dismiss();
    void Prompt(const QString &window_id);
Q_SIGNALS: // SIGNALS
    void Completed(bool dismissed, const QDBusVariant &result);
};
