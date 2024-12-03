#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Data::SqlClient; // Replace with MySqlClient if using MySQL
using namespace System::Drawing;

namespace FinalProjectVPN {

	public ref class UpdateProfileStudents : public System::Windows::Forms::Form
	{
	public:
		UpdateProfileStudents(void)
		{
			InitializeComponent();
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
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::Label^ label4;

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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(358, 276);
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
			this->label1->Size = System::Drawing::Size(82, 20);
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
			this->label2->Size = System::Drawing::Size(74, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Surname";
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
			this->label3->Size = System::Drawing::Size(46, 20);
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
			this->label4->Size = System::Drawing::Size(77, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Password";
			// 
			// UpdateProfileStudents
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(793, 346);
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
		System::String^ connectionString = "your_connection_string_here"; // Replace with your DB connection string

		void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				// Establish database connection
				SqlConnection^ connection = gcnew SqlConnection(connectionString);
				connection->Open();

				// Retrieve form data
				String^ firstName = textBox1->Text;
				String^ surname = textBox2->Text;
				String^ email = textBox3->Text;
				String^ password = textBox4->Text;

				// SQL query for updating student info
				String^ query = "UPDATE student SET FirstName = @FirstName, Surname = @Surname, Email = @Email, Password = @Password WHERE Email = @Email";

				SqlCommand^ command = gcnew SqlCommand(query, connection);
				command->Parameters->AddWithValue("@FirstName", firstName);
				command->Parameters->AddWithValue("@Surname", surname);
				command->Parameters->AddWithValue("@Email", email);
				command->Parameters->AddWithValue("@Password", password);

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
