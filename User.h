#pragma once

namespace UniversityRecords {

    using namespace System;

    public ref class User {
    public:
        String^ userID;
        String^ firstName;
        String^ lastName;
        String^ email;
        String^ passwordHash;
        String^ role;

        bool login(String^ email, String^ password);
        void logout();
        bool resetPassword(String^ email, String^ newPassword);
    protected:
        String^ hashPassword(String^ password);
    };
}
