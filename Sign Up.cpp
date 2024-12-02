// Sign Up.cpp
#include "Sign Up.h"

namespace FinalProjectVPN {

    // Constructor implementation
    SignUp::SignUp(void) {
        InitializeComponent();
        // TODO: Add the constructor code here
    }

    // Destructor implementation
    SignUp::~SignUp() {
        if (components) {
            delete components;
        }
    }

    // Event handler for label1 click
    System::Void SignUp::label1_Click(System::Object^ sender, System::EventArgs^ e) {
        // TODO: Add code to handle label1 click event
    }

    // Event handler for label7 click
    System::Void SignUp::label7_Click(System::Object^ sender, System::EventArgs^ e) {
        // TODO: Add code to handle label7 click event
    }

    // Event handler for linkLabel1 link clicked
    System::Void SignUp::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        // TODO: Add code to handle linkLabel1 link clicked event
    }

    // Event handler for button1 click
    System::Void SignUp::button1_Click(System::Object^ sender, System::EventArgs^ e) {
        // Validate input fields
        if (firstName->Text->Trim() == "" || lastName->Text->Trim() == "" || email->Text->Trim() == "" || password->Text->Trim() == "") {
            MessageBox::Show("Please fill in all fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        try {
            sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=university";
            sqlConn->Open();
            sqlCmd->Connection = sqlConn;
            sqlCmd->CommandText = "INSERT INTO users (firstName, lastName, email, password) VALUES (@firstName, @lastName, @email, @password)";
            sqlCmd->Parameters->AddWithValue("@firstName", firstName->Text);
            sqlCmd->Parameters->AddWithValue("@lastName", lastName->Text);
            sqlCmd->Parameters->AddWithValue("@email", email->Text);
            sqlCmd->Parameters->AddWithValue("@password", password->Text);
            sqlCmd->ExecuteNonQuery();
            sqlConn->Close();

            MessageBox::Show("Sign up successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
}
