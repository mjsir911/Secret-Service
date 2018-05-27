#ifndef SECRET_LOCK
#define SECRET_LOCK

#include <QObject>

#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

#include <QtCore/QObject>
#include <QtDBus/QtDBus>


typedef QMap<QString,QString> StringMap;
Q_DECLARE_METATYPE(StringMap)
// qDBusRegisterMetaType<StringMap>();

class SecretService : public QObject, public QDBusContext {
public:
SecretService(QObject *parent);
public slots:
	QDBusObjectPath ChangeLock(const QDBusObjectPath &collection);
	QDBusObjectPath CreateCollection(const QString &properties, const QString &alias, QDBusObjectPath &prompt);
	QString GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session);
	QList<QDBusObjectPath> Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt);
	void LockService(void);
	QDBusVariant OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &result);
	QDBusObjectPath ReadAlias(const QString &name);
	QList<QDBusObjectPath> SearchItems(StringMap &attributes, QList<QDBusObjectPath> &locked);
	void SetAlias(const QString &name, const QDBusObjectPath &collection);
	QList<QDBusObjectPath> Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt);
};

#endif
