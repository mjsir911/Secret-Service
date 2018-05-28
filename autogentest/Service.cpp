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
	throw NotImplementedException();
}
QDBusObjectPath _Service::CreateCollection(CollectionSpecifier properties, const QString &alias, QDBusObjectPath &prompt) {
	throw NotImplementedException();
}
SecretsDict _Service::GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session) {
	throw NotImplementedException();
}
QList<QDBusObjectPath> _Service::Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt) {
	throw NotImplementedException();
}
void _Service::LockService() {
	throw NotImplementedException();
}
QDBusVariant _Service::OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &result) {
	throw NotImplementedException();
}
QDBusObjectPath _Service::ReadAlias(const QString &name) {
	throw NotImplementedException();
}
QList<QDBusObjectPath> _Service::SearchItems(StringMap attributes, QList<QDBusObjectPath> &locked) {
	throw NotImplementedException();
}
void _Service::SetAlias(const QString &name, const QDBusObjectPath &collection) {
	throw NotImplementedException();
}
QList<QDBusObjectPath> _Service::Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt) {
	throw NotImplementedException();
}
