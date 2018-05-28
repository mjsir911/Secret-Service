#include <QtDBus/QtDBus>
#include "Types.h"

class _Item : public QObject, public QDBusContext{
	Q_OBJECT

public Q_SLOTS: // METHODS
    QDBusObjectPath Delete();
    SecretStruct GetSecret(const QDBusObjectPath &session);
    void SetSecret(SecretStruct secret);
Q_SIGNALS: // SIGNALS
};
