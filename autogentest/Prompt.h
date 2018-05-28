#include <QtDBus/QtDBus>
#include "Types.h"

class _Prompt : public QObject, public QDBusContext{
	Q_OBJECT

public Q_SLOTS: // METHODS
    void Dismiss();
    void Prompt(const QString &window_id);
Q_SIGNALS: // SIGNALS
    void Completed(bool dismissed, const QDBusVariant &result);
};
