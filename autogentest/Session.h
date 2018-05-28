#include <QtDBus/QtDBus>
#include "Types.h"

class _Session : public QObject, public QDBusContext{
	Q_OBJECT

public Q_SLOTS: // METHODS
    void Close();
Q_SIGNALS: // SIGNALS
};
