#include <iostream>
#include <stdio.h>
#include "Secret.h"

#include <sodium.h>

#include <cstring>

#define debugline() std::cerr << "DEBUG ###: " << __PRETTY_FUNCTION__ << " : " << __LINE__ << " : " << __FILE__ << "\n"

SecretService::SecretService(QObject *parent): QObject(parent) {}

QDBusObjectPath SecretService::ChangeLock(const QDBusObjectPath &collection) {}
QDBusObjectPath SecretService::CreateCollection(const QString &properties, const QString &alias, QDBusObjectPath &prompt) {}

SecretsDict SecretService::GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session) {
	debugline();
	qDebug() << items[0].path();

	SecretsDict ret;
	Secret secret = {session, QByteArray(), "third", "text/plain"};
	ret[items[0]] = secret;
	return ret;
}
QList<QDBusObjectPath> SecretService::Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt) {}
void SecretService::LockService(void) {}

QDBusVariant SecretService::OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &result) {
	debugline();
	result.setPath("/");
	if (algorithm == "plain") {
		// do something
		return QDBusVariant(QByteArray());
	} else if (algorithm == "dh-ietf1024-sha256-aes128-cbc-pkcs7") {

		QByteArray data = input.variant().value<QByteArray>();

		unsigned char other_publickey[data.length()];
		std::memcpy(other_publickey, data.data(), sizeof other_publickey);


		unsigned char my_publickey[crypto_box_PUBLICKEYBYTES];
		unsigned char my_secretkey[crypto_box_SECRETKEYBYTES];
		randombytes_buf(my_secretkey, sizeof my_secretkey);
		crypto_scalarmult_base(my_publickey, my_secretkey);

		unsigned char scalarmult_q_by_server[crypto_scalarmult_BYTES];
		if (crypto_scalarmult(scalarmult_q_by_server, my_secretkey, other_publickey)) {
			// ERROR
		}
		crypto_generichash_state h;
		unsigned char sharedkey[crypto_generichash_BYTES];

		crypto_generichash_init(&h, NULL, 0U, sizeof sharedkey);
		crypto_generichash_update(&h, scalarmult_q_by_server, sizeof scalarmult_q_by_server);
		crypto_generichash_update(&h, other_publickey, sizeof other_publickey);
		crypto_generichash_update(&h, my_publickey, sizeof my_publickey);
		crypto_generichash_final(&h, sharedkey, sizeof sharedkey);

		std::cerr << sharedkey << "\n";

		return QDBusVariant(QByteArray((const char *)my_publickey, crypto_box_PUBLICKEYBYTES));
	} else {
		sendErrorReply(QDBusError::NotSupported, "um, no"); 
	}


	/*
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
	*/

	//const QDBusMessage z = QDBusMessage::createError("hello", "no");

	//this->bus->send(z);


	//std::cerr << input << "\n";
}


QDBusObjectPath SecretService::ReadAlias(const QString &name) {}
QList<QDBusObjectPath> SecretService::SearchItems(StringMap &attributes, QList<QDBusObjectPath> &locked) {
	debugline();
	qDebug() << attributes << "\n";

	QList<QDBusObjectPath> list = {QDBusObjectPath("/org/freedesktop/secrets/collection/xxxx/iiii")};

	//locked = list;
	return list;
}
void SecretService::SetAlias(const QString &name, const QDBusObjectPath &collection) {}
QList<QDBusObjectPath> SecretService::Unlock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &prompt) {}
