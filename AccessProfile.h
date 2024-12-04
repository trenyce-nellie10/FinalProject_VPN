#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace MySql::Data::MySqlClient; // Use MySqlClient for MySQL
using namespace System::Drawing;

namespace FinalProjectVPN {

	public ref class AccessProfile : public System::Windows::Forms::Form
	{
	private:
		int userID; // Add userID as a member variable

	public:
		AccessProfile(int userID)
		{
			InitializeComponent();
			this->userID = userID; // Assign userID to the class variable
			LoadProfileData(); // Load the profile data when the form is initialized
		}

	protected:
		~AccessProfile()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ firstName;
		System::Windows::Forms::TextBox^ lastName;
		System::Windows::Forms::TextBox^ email;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ password;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::TextBox^ major;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::TextBox^ studentID;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::PictureBox^ pictureBox1;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->firstName = (gcnew System::Windows::Forms::TextBox());
			this->lastName = (gcnew System::Windows::Forms::TextBox());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->major = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->studentID = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(216, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First name";
			// 
			// firstName
			// 
			this->firstName->Location = System::Drawing::Point(309, 55);
			this->firstName->Name = L"firstName";
			this->firstName->Size = System::Drawing::Size(213, 26);
			this->firstName->TabIndex = 2;
			this->firstName->ReadOnly = true;
			// 
			// lastName
			// 
			this->lastName->Location = System::Drawing::Point(309, 116);
			this->lastName->Name = L"lastName";
			this->lastName->Size = System::Drawing::Size(213, 26);
			this->lastName->TabIndex = 3;
			this->lastName->ReadOnly = true;
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(309, 178);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(213, 26);
			this->email->TabIndex = 5;
			this->email->ReadOnly = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(219, 119);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Last name";
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(309, 242);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(213, 26);
			this->password->TabIndex = 7;
			this->password->ReadOnly = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(244, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Email";
			// 
			// major
			// 
			this->major->Location = System::Drawing::Point(309, 305);
			this->major->Name = L"major";
			this->major->Size = System::Drawing::Size(213, 26);
			this->major->TabIndex = 9;
			this->major->ReadOnly = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(216, 245);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Password";
			// 
			// studentID
			// 
			this->studentID->Location = System::Drawing::Point(309, 370);
			this->studentID->Name = L"studentID";
			this->studentID->Size = System::Drawing::Size(213, 26);
			this->studentID->TabIndex = 11;
			this->studentID->ReadOnly = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(216, 373);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(82, 20);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Student ID";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(32, 55);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(165, 210);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// AccessProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(765, 517);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->studentID);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->major);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->password);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->email);
			this->Controls->Add(this->lastName);
			this->Controls->Add(this->firstName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AccessProfile";
			this->Text = L"Access Profile - Students";
			this->Load += gcnew System::EventHandler(this, &AccessProfile::AccessProfile_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AccessProfile_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadProfileData();
	}

	private: void LoadProfileData() {
		String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		String^ query = "SELECT u.firstName, u.lastName, u.email, u.password, s.major, s.studentID " +
			"FROM users u " +
			"JOIN student s ON u.userID = s.userID " +
			"WHERE u.userID = @userID";

		MySqlCommand^ command = gcnew MySqlCommand(query, connection);
		command->Parameters->AddWithValue("@userID", userID);

		try
		{
			connection->Open();
			MySqlDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				firstName->Text = reader["firstName"]->ToString();
				lastName->Text = reader["lastName"]->ToString();
				email->Text = reader["email"]->ToString();
				password->Text = reader["password"]->ToString();
				major->Text = reader["major"]->ToString();
				studentID->Text = reader["studentID"]->ToString();
			}
			else
			{
				MessageBox::Show("No matching record found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error loading profile data: " + ex->Message);
		}
		finally
		{
			connection->Close();
		}
	}
	};
}
