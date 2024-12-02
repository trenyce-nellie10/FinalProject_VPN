#pragma once

namespace FinalProjectVPN {

    using namespace System;
    using namespace System::Collections::Generic;

    public ref class Role {
    public:
        String^ roleName;
        List<String^>^ permissions;

        Role(String^ roleName) {
            this->roleName = roleName;
            this->permissions = gcnew List<String^>();
        }

        void addPermission(String^ permission) {
            this->permissions->Add(permission);
        }

        bool hasPermission(String^ permission) {
            return this->permissions->Contains(permission);
        }
    };
}
