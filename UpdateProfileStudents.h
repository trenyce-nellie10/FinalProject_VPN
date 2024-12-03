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

	public ref class UpdateProfileStudents : public System::Windows::Forms::Form
	{
	public:
		UpdateProfileStudents(int studentID)
		{
			InitializeComponent();
			this->studentID = studentID;
			LoadStudentData();
		}

	protected:
		~UpdateProfileStudents()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int studentID;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::TextBox^ textBox5;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::TextBox^ textBox6;
		System::Windows::Forms::Label^ label6;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(365, 399);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Update";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UpdateProfileStudents::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(203, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"First Name";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(306, 47);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(196, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(306, 103);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(196, 26);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(211, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Last Name";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(306, 162);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(196, 26);
			this->textBox3->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(234, 162);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Email";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(306, 218);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(196, 26);
			this->textBox4->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(203, 221);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Password";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(306, 274);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(196, 26);
			this->textBox5->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(234, 277);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Major";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(306, 330);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(196, 26);
			this->textBox6->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(203, 333);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(87, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Student ID";
			// 
			// UpdateProfileStudents
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(839, 472);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"UpdateProfileStudents";
			this->Text = L"Update Profile - Students";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';"; // Replace with your DB connection string

		void LoadStudentData()
		{
			try
			{
				// Establish database connection
				MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
				connection->Open();

				// SQL query for retrieving student info
				String^ query = "SELECT u.FirstName, u.LastName, u.Email, u.Password, s.Major FROM users u JOIN student s ON u.UserID = s.UserID WHERE s.StudentID = @StudentID";

				MySqlCommand^ command = gcnew MySqlCommand(query, connection);
				command->Parameters->AddWithValue("@StudentID", studentID);

				MySqlDataReader^ reader = command->ExecuteReader();
				if (reader->Read())
				{
					textBox1->Text = reader["FirstName"]->ToString();
					textBox2->Text = reader["LastName"]->ToString();
					textBox3->Text = reader["Email"]->ToString();
					textBox4->Text = reader["Password"]->ToString();
					textBox5->Text = reader["Major"]->ToString();
					textBox6->Text = studentID.ToString();
				}
				else
				{
					MessageBox::Show("No matching record found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

				connection->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				// Establish database connection
				MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
				connection->Open();

				// Retrieve form data
				String^ firstName = textBox1->Text;
				String^ lastName = textBox2->Text;
				String^ email = textBox3->Text;
				String^ password = textBox4->Text;

				// SQL query for updating student info
				String^ query = "UPDATE users u JOIN student s ON u.userID = s.userID SET u.FirstName = @FirstName, u.LastName = @LastName, u.Email = @Email, u.Password = @Password WHERE s.StudentID = @StudentID";

				MySqlCommand^ command = gcnew MySqlCommand(query, connection);
				command->Parameters->AddWithValue("@FirstName", firstName);
				command->Parameters->AddWithValue("@LastName", lastName);
				command->Parameters->AddWithValue("@Email", email);
				command->Parameters->AddWithValue("@Password", password);
				command->Parameters->AddWithValue("@StudentID", studentID);

				int rowsAffected = command->ExecuteNonQuery();
				if (rowsAffected > 0)
				{
					MessageBox::Show("Profile updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else
				{
					MessageBox::Show("No matching record found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

				connection->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	};
}

