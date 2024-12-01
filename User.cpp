#include "User.h"
#include <System::Security::Cryptography::SHA256Managed.h>
#include <System::Text::Encoding.h>

using namespace System::Security::Cryptography;
using namespace System::Text;

bool UniversityRecords::User::login(String^ email, String^ password) {
    // Fetch user from database using email
    // For demonstration, assume user is fetched and passwordHash is set
    String^ storedPasswordHash = this->passwordHash;

    // Hash the input password
    String^ inputPasswordHash = hashPassword(password);

    // Compare the hashed passwords
    if (storedPasswordHash == inputPasswordHash) {
        // Successful login
        return true;
    } else {
        // Failed login
        return false;
    }
}

void UniversityRecords::User::logout() {
    // Implement logout functionality
}

bool UniversityRecords::User::resetPassword(String^ email, String^ newPassword) {
    // Fetch user from database using email
    // For demonstration, assume user is fetched

    // Hash the new password
    String^ newPasswordHash = hashPassword(newPassword);

    // Update the password in the database
    // For demonstration, assume the password is updated successfully
    this->passwordHash = newPasswordHash;
    return true;
}

String^ UniversityRecords::User::hashPassword(String^ password) {
    SHA256Managed^ sha256 = gcnew SHA256Managed();
    array<Byte>^ passwordBytes = Encoding::UTF8->GetBytes(password);
    array<Byte>^ hashBytes = sha256->ComputeHash(passwordBytes);
    return BitConverter::ToString(hashBytes)->Replace("-", "");
}
