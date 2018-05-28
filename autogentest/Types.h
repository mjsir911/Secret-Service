#ifndef TYPES_H
#define TYPES_H

#include <QtDBus/QtDBus>

struct SecretStruct {
	QDBusObjectPath session;
	QByteArray parameters;
	QByteArray value;
	QString content_type;
	friend QDBusArgument &operator<<(QDBusArgument &argument, const SecretStruct &mystruct);
	const friend QDBusArgument &operator>>(const QDBusArgument &argument, SecretStruct &mystruct);
};
Q_DECLARE_METATYPE(SecretStruct)

QDBusArgument &operator<<(QDBusArgument &argument, const SecretStruct &mystruct);
const QDBusArgument &operator>>(const QDBusArgument &argument, SecretStruct &mystruct);

typedef QMap<QDBusObjectPath, SecretStruct> SecretsDict;
Q_DECLARE_METATYPE(SecretsDict)


typedef QMap<QString,QString> StringMap;
Q_DECLARE_METATYPE(StringMap)

typedef QMap<QString, QDBusVariant> CollectionSpecifier;
Q_DECLARE_METATYPE(CollectionSpecifier)
void registerMetaTypes(void);

#endif
