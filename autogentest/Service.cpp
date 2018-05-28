#include "Service.h"
#include "ServiceAdaptor.h"
#include "ServiceInterface.h"

_Service::_Service(QObject *parent, QDBusConnection &bus) : QObject(parent) {
	new ServiceAdaptor(this);
	new OrgFreedesktopSecretServiceInterface("org.freedesktop.Secret.Service", "org/freedesktop/secrets", bus, this);

	bus.registerService("org.freedesktop.Secret.Service");
	bus.registerService("org.freedesktop.secrets");
	bus.registerObject("/org/freedesktop/secrets", this);

}

#include "Utils.h"

QDBusObjectPath _Service::ChangeLock(const QDBusObjectPath &collection) {
	debugline()
	throw NotImplementedException();
}
QDBusObjectPath _Service::CreateCollection(CollectionSpecifier properties, const QString &alias, QDBusObjectPath &prompt) {
	debugline()
	throw NotImplementedException();
}
SecretsDict _Service::GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session) {
	debugline()
	throw NotImplementedException();
}
QList<QDBusObjectPath> _Service::Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt) {
	debugline()
	throw NotImplementedException();
}
void _Service::LockService() {
	debugline()
	throw NotImplementedException();
}
QDBusVariant _Service::OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &result) {
	debugline()
	throw NotImplementedException();
}
QDBusObjectPath _Service::ReadAlias(const QString &name) {
	debugline()
	throw NotImplementedException();
}
QList<QDBusObjectPath> _Service::SearchItems(StringMap attributes, QList<QDBusObjectPath> &locked) {
	debugline()
	throw NotImplementedException();
}
void _Service::SetAlias(const QString &name, const QDBusObjectPath &collection) {
	debugline()
	throw NotImplementedException();
}
QList<QDBusObjectPath> _Service::Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt) {
	debugline()
	throw NotImplementedException();
}
