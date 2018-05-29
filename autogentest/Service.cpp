#include "Service.h"
#include "ServiceAdaptor.h"
#include "ServiceInterface.h"

#include "Prompt.h"

#include "Utils.h"

_Service::_Service(QObject *parent, QDBusConnection &bus) : QObject(parent), bus(bus) {
	new ServiceAdaptor(this);
	new OrgFreedesktopSecretServiceInterface(interface, path.path(), bus, this);

	bus.registerService(interface);
	bus.registerObject(path.path(), this);

}

QDBusObjectPath _Service::generatePath(void) {
	return QDBusObjectPath("/org/freedesktop/secrets/session/" + GetRandomString(12));
}


QDBusObjectPath _Service::ChangeLock(const QDBusObjectPath &collection) {
	debugline();
	throw NotImplementedException();
}

QDBusObjectPath _Service::CreateCollection(CollectionSpecifier properties, const QString &alias, QDBusObjectPath &prompt) {
	debugline();
	throw NotImplementedException();
}


#include "Item.h"
SecretsDict _Service::GetSecrets(const QList<QDBusObjectPath> &items, const QDBusObjectPath &session) {
	debugline();
	SecretsDict ret;
	for( int i=0; i < items.count(); ++i) {
		QDBusObjectPath secretPath = items[i];
		debugline();
		_Item secret(this, bus, secretPath);
		ret[secretPath] = secret.GetSecret(session);
	}
	return ret;
}

QList<QDBusObjectPath> _Service::Lock(const QList<QDBusObjectPath> &objects, QDBusObjectPath &Prompt) {
	debugline();
	throw NotImplementedException();
}

void _Service::LockService() {
	debugline();
	throw NotImplementedException();
}

#include <cstring>
#include <gcrypt.h>
// #include "egg/egg-dh.h"
#include "egg.h"

// EGG_SECURE_DEFINE_GLIB_GLOBALS ();

QByteArray convert(gcry_mpi_t number) {
		unsigned char *buffer; // Do I have to free this?
		size_t n_buffer;

		gcry_mpi_aprint(GCRYMPI_FMT_USG, &buffer, &n_buffer, number); // TODO: check return val
		return QByteArray(reinterpret_cast<char *>(buffer), n_buffer);
}

QDBusVariant _Service::OpenSession(const QString &algorithm, const QDBusVariant &input, QDBusObjectPath &sessionPath) {
	debugline();
	sessionPath = generatePath();
	if (algorithm == "plain") {
		encryptionDict[sessionPath] = QByteArray();
		return QDBusVariant(QByteArray());
	} else if (algorithm == "dh-ietf1024-sha256-aes128-cbc-pkcs7") {
		QByteArray peer_data = input.variant().value<QByteArray>();






		egg_libgcrypt_initialize();
		gcry_mpi_t prime, base, my_publickey, my_privatekey;
		egg_dh_default_params("ietf-ike-grp-modp-1024", &prime, &base); // TODO: check return val
		egg_dh_gen_pair(prime, base, 0, &my_publickey, &my_privatekey); // TODO: check return val

		gcry_mpi_t peer;
		gcry_mpi_scan(&peer, GCRYMPI_FMT_USG, peer_data, peer_data.length(), NULL);

		QByteArray sharedkey;

		{
			void *ikm;
			size_t n_ikm;
			ikm = egg_dh_gen_secret(peer, my_privatekey, prime, &n_ikm);

			size_t n_hashed = 16;
			char hashed[n_hashed];
			egg_hkdf_perform ("sha256", ikm, n_ikm, NULL, 0, NULL, 0, hashed, n_hashed);
			sharedkey = QByteArray(hashed, n_hashed);
		}

		encryptionDict[sessionPath] = sharedkey;

		return QDBusVariant(convert(my_publickey));
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
