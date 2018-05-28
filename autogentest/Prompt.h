#ifndef PROMPT_H
#define PROMPT_H
#include <QtDBus/QtDBus>
#include "Types.h"

class _Prompt : public QObject, public QDBusContext{
	Q_OBJECT

public:
		_Prompt(QObject *, QDBusConnection &);

public Q_SLOTS: // METHODS
    void Dismiss();
    void Prompt(const QString &window_id);
Q_SIGNALS: // SIGNALS
    void Completed(bool dismissed, const QDBusVariant &result);
};
#endif
