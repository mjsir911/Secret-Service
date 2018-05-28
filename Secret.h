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

struct Secret{
	QDBusObjectPath session;
	QByteArray parameters;
	QByteArray value;
	QString content_type;
	friend QDBusArgument &operator<<(QDBusArgument &argument, const Secret &mystruct);
	const friend QDBusArgument &operator>>(const QDBusArgument &argument, Secret &mystruct);
};
Q_DECLARE_METATYPE(Secret)
QDBusArgument &operator<<(QDBusArgument &argument, const Secret &mystruct);
const QDBusArgument &operator>>(const QDBusArgument &argument, Secret &mystruct);

typedef QMap<QDBusObjectPath, Secret> SecretsDict;
Q_DECLARE_METATYPE(SecretsDict)


typedef QMap<QString,QString> StringMap;
Q_DECLARE_METATYPE(StringMap)
// qDBusRegisterMetaType<StringMap>();

class SecretService : public QObject, public QDBusContext {
	Q_OBJECT
public:
SecretService(QObject *parent);
public slots:
	QDBusObjectPath ChangeLock(const QDBusObjectPath &collection);
	QDBusObjectPath CreateCollection(const QString &properties, const QString &alias, QDBusObjectPath &prompt);
	SecretsDict GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session);
	QList<QDBusObjectPath> Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt);
	void LockService(void);
	QDBusVariant OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &result);
	QDBusObjectPath ReadAlias(const QString &name);
	QList<QDBusObjectPath> SearchItems(StringMap &attributes, QList<QDBusObjectPath> &locked);
	void SetAlias(const QString &name, const QDBusObjectPath &collection);
	QList<QDBusObjectPath> Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt);
};

#endif
