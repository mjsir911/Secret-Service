#include <iostream>
#include <stdio.h>
#include "Secret.h"

#include <crypto++/cryptlib.h>
#include <crypto++/osrng.h>
#include <crypto++/dh.h>
#include <crypto++/nbtheory.h>

SecretService::SecretService(QObject *parent): QObject(parent) {}

QDBusObjectPath SecretService::ChangeLock(const QDBusObjectPath &collection) {}
QDBusObjectPath SecretService::CreateCollection(const QString &properties, const QString &alias, QDBusObjectPath &prompt) {}
QString SecretService::GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session) {}
QList<QDBusObjectPath> SecretService::Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt) {}
void SecretService::LockService(void) {}

QDBusVariant SecretService::OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &result) {
	//sendErrorReply(QDBusError::NotSupported); # BUG: sendErrorReply crashes everything beacause calledFromDBus() is false
	if (algorithm == "plain") {
		// do something
	} else if (algorithm == "dh-ietf1024-sha256-aes128-cbc-pkcs7") {
		std::cerr << "hello from the inside\n";
	} else {
		// org.freedesktop.DBus.Error.NotSupported
	}
	result.setPath("/");

	CryptoPP::AutoSeededRandomPool prng;
	CryptoPP::Integer p, q, g;
	CryptoPP::PrimeAndGenerator pg;

  pg.Generate(1, prng, 512, 511);
  p = pg.Prime();
  q = pg.SubPrime();
  g = pg.Generator();

	CryptoPP::DH dh(p, q, g);
	CryptoPP::SecByteBlock t1(dh.PrivateKeyLength()), t2(dh.PublicKeyLength());
  dh.GenerateKeyPair(prng, t1, t2);
	CryptoPP::Integer k1(t1, t1.size()), k2(t2, t2.size());

	std::cout << "Private key:\n";
	std::cout << std::hex << k1 << std::endl;

	std::cout << "Public key:\n";
  std::cout << std::hex << k2 << std::endl;

	unsigned char z[k2.MinEncodedSize()] ;
	k2.Encode(z, k2.MinEncodedSize());
	return QDBusVariant(QByteArray::fromRawData((const char *)z, k2.MinEncodedSize()));

	//const QDBusMessage z = QDBusMessage::createError("hello", "no");

	//this->bus->send(z);


	//std::cerr << input << "\n";
}


QDBusObjectPath SecretService::ReadAlias(const QString &name) {}
QList<QDBusObjectPath> SecretService::SearchItems(StringMap &attributes, QList<QDBusObjectPath> &locked) {
	std::cerr << "YOOOOOO\n";
}
void SecretService::SetAlias(const QString &name, const QDBusObjectPath &collection) {}
QList<QDBusObjectPath> SecretService::Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt) {}
