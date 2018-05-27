#include <iostream>
#include <stdio.h>
#include "Secret.h"

SecretService::SecretService(QObject *parent): QObject(parent) {}

QDBusObjectPath SecretService::ChangeLock(const QDBusObjectPath &collection) {}
QDBusObjectPath SecretService::CreateCollection(const QString &properties, const QString &alias, QDBusObjectPath &prompt) {}
QString SecretService::GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session) {}
QList<QDBusObjectPath> SecretService::Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt) {}
void SecretService::LockService(void) {}

QDBusVariant SecretService::OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &result) {
	if (algorithm == "plain") {
		// do something
	} else if (algorithm == "dh-ietf1024-sha256-aes128-cbc-pkcs7") {
		std::cerr << "hello from the inside\n";
	} else {
		// org.freedesktop.DBus.Error.NotSupported
	}
	result.setPath("/");
	return QDBusVariant("/");

	//std::cerr << input << "\n";
}


QDBusObjectPath SecretService::ReadAlias(const QString &name) {}
QList<QDBusObjectPath> SecretService::SearchItems(const QString &attributes, QList<QDBusObjectPath> &locked) {}
void SecretService::SetAlias(const QString &name, const QDBusObjectPath &collection) {}
QList<QDBusObjectPath> SecretService::Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt) {}
