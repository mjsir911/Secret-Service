#include "Service.h"
#include "ServiceAdaptor.h"
#include "ServiceInterface.h"

#include "Prompt.h"

_Service::_Service(QObject *parent, QDBusConnection &bus) : QObject(parent), bus(bus) {
	new ServiceAdaptor(this);
	new OrgFreedesktopSecretServiceInterface(interface, path.path(), bus, this);

	bus.registerService(interface);
	bus.registerObject(path.path(), this);

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
#define database_locked false
	if (database_locked) { // If keepassxc database is locked
		throw NotImplementedException();
		//locked = {QDBusObjectPath("/org/freedesktop/secrets/collection/xxxx")};
		locked = {QDBusObjectPath("/org/freedesktop/secrets/aliases/default")};
		return QList<QDBusObjectPath>();
	} else {
		locked = {QDBusObjectPath("/org/freedesktop/secrets/aliases/default")};
		// TODO: search database
		return QList<QDBusObjectPath>();
	}
}

void _Service::SetAlias(const QString &name, const QDBusObjectPath &collection) {
	debugline();
	throw NotImplementedException();
}

QList<QDBusObjectPath> _Service::Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt) {
	debugline();
	prompt = (new _Prompt(this, bus, objects))->path; // hmmm
	return QList<QDBusObjectPath>(); // If we ever get this far, there are probably no unlocked objects
}
