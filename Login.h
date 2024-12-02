#pragma once
#include "Dashboard.h"

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{

	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ email;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ email_txt;
	private: System::Windows::Forms::TextBox^ password_txt;
	private: System::Windows::Forms::Button^ cancel_button;



	private: System::Windows::Forms::Button^ login_button;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->email = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->email_txt = (gcnew System::Windows::Forms::TextBox());
			this->password_txt = (gcnew System::Windows::Forms::TextBox());
			this->cancel_button = (gcnew System::Windows::Forms::Button());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// email
			// 
			this->email->AutoSize = true;
			this->email->Location = System::Drawing::Point(219, 111);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(48, 20);
			this->email->TabIndex = 0;
			this->email->Text = L"Email";
			this->email->Click += gcnew System::EventHandler(this, &Login::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(219, 185);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password";
			this->label2->Click += gcnew System::EventHandler(this, &Login::label2_Click);
			// 
			// email_txt
			// 
			this->email_txt->Location = System::Drawing::Point(322, 105);
			this->email_txt->Name = L"email_txt";
			this->email_txt->Size = System::Drawing::Size(326, 26);
			this->email_txt->TabIndex = 2;
			this->email_txt->TextChanged += gcnew System::EventHandler(this, &Login::Login_Load);
			// 
			// password_txt
			// 
			this->password_txt->Location = System::Drawing::Point(322, 179);
			this->password_txt->Name = L"password_txt";
			this->password_txt->Size = System::Drawing::Size(326, 26);
			this->password_txt->TabIndex = 3;
			this->password_txt->TextChanged += gcnew System::EventHandler(this, &Login::textBox2_TextChanged);
			// 
			// cancel_button
			// 
			this->cancel_button->BackColor = System::Drawing::Color::LightCoral;
			this->cancel_button->Location = System::Drawing::Point(227, 271);
			this->cancel_button->Name = L"cancel_button";
			this->cancel_button->Size = System::Drawing::Size(86, 31);
			this->cancel_button->TabIndex = 4;
			this->cancel_button->Text = L"Cancel";
			this->cancel_button->UseVisualStyleBackColor = false;
			// 
			// login_button
			// 
			this->login_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->login_button->Location = System::Drawing::Point(562, 271);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(86, 31);
			this->login_button->TabIndex = 5;
			this->login_button->Text = L"Login";
			this->login_button->UseVisualStyleBackColor = false;
			this->login_button->Click += gcnew System::EventHandler(this, &Login::button2_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(835, 389);
			this->Controls->Add(this->login_button);
			this->Controls->Add(this->cancel_button);
			this->Controls->Add(this->password_txt);
			this->Controls->Add(this->email_txt);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->email);
			this->Name = L"MyForm2";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ connString = "Server=localhost;Database=university;Uid=root;Pwd="";";
		MySqlConnection^ conn = gcnew MySqlConnection(connString);
		try {
			conn->Open();
			String^ email = email_txt->Text;
			String^ password = password_txt->Text;
			String^ query = "SELECT * FROM users WHERE email=@Email AND password=@Password";
			MySqlCommand^ cmd = gcnew MySqlCommand(query, conn);
			cmd->Parameters->AddWithValue("@Email", email);
			cmd->Parameters->AddWithValue("@Password", password);
			MySqlDataReader^ reader = cmd->ExecuteReader();
			if (reader->Read()) {
				this->Hide();
				Dashboard^ dashboard = gcnew Dashboard();
				dashboard->ShowDialog();
				this->Show();
			}
			else {
				MessageBox::Show("Invalid email or password", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			reader->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			conn->Close();
		}



	}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
