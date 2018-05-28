#include <QtDBus/QtDBus>
#include "Types.h"

class _Collection : public QObject, public QDBusContext{
	Q_OBJECT

public Q_SLOTS: // METHODS
    QDBusObjectPath CreateItem(CollectionSpecifier properties, SecretStruct secret, bool replace, QDBusObjectPath &prompt);
    QDBusObjectPath Delete();
    QList<QDBusObjectPath> SearchItems(StringMap attributes);
Q_SIGNALS: // SIGNALS
    void ItemChanged(const QDBusObjectPath &item);
    void ItemCreated(const QDBusObjectPath &item);
    void ItemDeleted(const QDBusObjectPath &item);
};
