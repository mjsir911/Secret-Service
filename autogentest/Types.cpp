#include <QtDBus/QtDBus>

#include "Types.h"

void registerMetaTypes() {
	qDBusRegisterMetaType<StringMap>();
	qDBusRegisterMetaType<SecretStruct>();
	qDBusRegisterMetaType<SecretsDict>();
	qDBusRegisterMetaType<CollectionsSpecifier>();
}

QDBusArgument &operator<<(QDBusArgument &argument, const SecretStruct &mystruct) {
    argument.beginStructure();
    argument << mystruct.session << mystruct.parameters << mystruct.value << mystruct.content_type;
    argument.endStructure();
    return argument;
}

// Retrieve the MyStructure data from the D-Bus argument
const QDBusArgument &operator>>(const QDBusArgument &argument, SecretStruct &mystruct) {
    argument.beginStructure();
    argument >> mystruct.session >> mystruct.parameters >> mystruct.value >> mystruct.content_type;
    argument.endStructure();
    return argument;
}
