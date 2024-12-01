#include "Role.h"

using namespace UniversityRecords;

void Role::addPermission(String^ permission) {
    this->permissions->Add(permission);
}

bool Role::hasPermission(String^ permission) {
    return this->permissions->Contains(permission);
}
