#include "Service.h"
#include "ServiceAdaptor.h"
#include "ServiceInterface.h"

_Service::_Service(QObject *parent, QDBusConnection &bus) : QObject(parent) {
	new ServiceAdaptor(this);
	new OrgFreedesktopSecretServiceInterface("org.freedesktop.Secret.Service", "org/freedesktop/secrets", bus, this);

	bus.registerService("org.freedesktop.Secret.Service");
	bus.registerObject("/org/freedesktop/secrets", this);

}

#include "Utils.h"

QDBusObjectPath _Service::ChangeLock(const QDBusObjectPath &collection) {
	debugline();
	throw NotImplementedException();
}
QDBusObjectPath _Service::CreateCollection(CollectionSpecifier properties, const QString &alias, QDBusObjectPath &prompt) {
	debugline();
	throw NotImplementedException();
}
SecretsDict _Service::GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session) {
	debugline();
	SecretsDict ret;
	SecretStruct secret = {session, QByteArray(), "third", "text/plain"};
	ret[items[0]] = secret;
	return ret;
	throw NotImplementedException();
}
QList<QDBusObjectPath> _Service::Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt) {
	debugline();
	throw NotImplementedException();
}
void _Service::LockService() {
	debugline();
	throw NotImplementedException();
}
QDBusVariant _Service::OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &result) {
	debugline();
	result.setPath("/");
	if (algorithm == "plain") {
		return QDBusVariant(QByteArray());
	} else if (algorithm == "dh-ietf1024-sha256-aes128-cbc-pkcs7") {
		throw NotImplementedException();
	} else {
		sendErrorReply(QDBusError::NotSupported, "um, no"); 
	}
}
QDBusObjectPath _Service::ReadAlias(const QString &name) {
	debugline();
	throw NotImplementedException();
}
QList<QDBusObjectPath> _Service::SearchItems(StringMap attributes, QList<QDBusObjectPath> &locked) {
	debugline();
	// QList<QDBusObjectPath> list = {QDBusObjectPath("/org/freedesktop/secrets/collection/xxxx/iiii")};
	QList<QDBusObjectPath> list = {QDBusObjectPath("/org/freedesktop/secrets/collection/xxxx")};
	locked = list;
	return QList<QDBusObjectPath>();
}
void _Service::SetAlias(const QString &name, const QDBusObjectPath &collection) {
	debugline();
	throw NotImplementedException();
}
QList<QDBusObjectPath> _Service::Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt) {
	debugline();
	prompt = QDBusObjectPath("/org/freedesktop/secrets/prompts/name");
	return QList<QDBusObjectPath>();
}
