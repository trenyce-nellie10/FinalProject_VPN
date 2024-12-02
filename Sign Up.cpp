// Sign Up.cpp
#include "Sign Up.h"

namespace FinalProjectVPN {

    // Constructor implementation
    MyForm::MyForm(void) {
        InitializeComponent();
        // TODO: Add the constructor code here
    }

    // Destructor implementation
    MyForm::~MyForm() {
        if (components) {
            delete components;
        }
    }

    // Event handler for label1 click
    System::Void MyForm::label1_Click(System::Object^ sender, System::EventArgs^ e) {
        // TODO: Add code to handle label1 click event
    }

    // Event handler for label7 click
    System::Void MyForm::label7_Click(System::Object^ sender, System::EventArgs^ e) {
        // TODO: Add code to handle label7 click event
    }

    // Event handler for linkLabel1 link clicked
    System::Void MyForm::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
        // TODO: Add code to handle linkLabel1 link clicked event
    }
}
