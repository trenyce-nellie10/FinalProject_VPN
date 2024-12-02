#pragma once



namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace MySql::Data::MySqlClient;    
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
	public:
		MySqlDataReader^ sqlRd;
		SignUp(void)
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
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ firstName;
	private: System::Windows::Forms::TextBox^ email;


	private: System::Windows::Forms::TextBox^ lastName;




	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ password;


	private: System::Windows::Forms::Label^ label4;





	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->firstName = (gcnew System::Windows::Forms::TextBox());
			this->email = (gcnew System::Windows::Forms::TextBox());
			this->lastName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(274, 146);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First name";
			this->label1->Click += gcnew System::EventHandler(this, &SignUp::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(274, 218);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"email";
			// 
			// firstName
			// 
			this->firstName->Location = System::Drawing::Point(359, 140);
			this->firstName->Name = L"firstName";
			this->firstName->Size = System::Drawing::Size(142, 26);
			this->firstName->TabIndex = 2;
			// 
			// email
			// 
			this->email->Location = System::Drawing::Point(359, 212);
			this->email->Name = L"email";
			this->email->Size = System::Drawing::Size(365, 26);
			this->email->TabIndex = 3;
			// 
			// lastName
			// 
			this->lastName->Location = System::Drawing::Point(637, 140);
			this->lastName->Name = L"lastName";
			this->lastName->Size = System::Drawing::Size(142, 26);
			this->lastName->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(552, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Last name";
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(359, 279);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(365, 26);
			this->password->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(275, 285);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Password";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(500, 348);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 34);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Sign up";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SignUp::button1_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(411, 102);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(192, 20);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Already have an account\?";
			this->label7->Click += gcnew System::EventHandler(this, &SignUp::label7_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(609, 102);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(48, 20);
			this->linkLabel1->TabIndex = 14;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Login";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SignUp::linkLabel1_LinkClicked);
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(971, 416);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->password);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lastName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->email);
			this->Controls->Add(this->firstName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"SignUp";
			this->Text = L"SignUp";
			this->Load += gcnew System::EventHandler(this, &SignUp::SignUp_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void SignUp_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	sqlConn->ConnectionString = "datasource = localhost; port=3306; username=root; password=; database=university";
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;
	sqlCmd->CommandText = "Select * from university";
	sqlRd = sqlCmd->ExecuteReader();
	sqlDt->Load(sqlRd);
	sqlRd->Close();
	sqlConn->Close();
	d
            #pragma once

            namespace FinalProjectVPN {

													using namespace System;
													using namespace System::ComponentModel;
													using namespace System::Collections;
													using namespace System::Windows::Forms;
													using namespace System::Data;
													using namespace MySql::Data::MySqlClient;
													using namespace System::Drawing;

													public ref class SignUp : public System::Windows::Forms::Form
													{
														MySqlConnection^ sqlConn = gcnew MySqlConnection();
														MySqlCommand^ sqlCmd = gcnew MySqlCommand();
														DataTable^ sqlDt = gcnew DataTable();
														MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
													public:
														MySqlDataReader^ sqlRd;
														SignUp(void)
														{
															InitializeComponent();
														}

													protected:
														~SignUp()
														{
															if (components)
															{
																delete components;
															}
														}
													private: System::Windows::Forms::Label^ label1;
													private: System::Windows::Forms::Label^ label2;
													private: System::Windows::Forms::TextBox^ firstName;
													private: System::Windows::Forms::TextBox^ email;
													private: System::Windows::Forms::TextBox^ lastName;
													private: System::Windows::Forms::Label^ label3;
													private: System::Windows::Forms::TextBox^ password;
													private: System::Windows::Forms::Label^ label4;
													private: System::Windows::Forms::Button^ button1;
													private: System::Windows::Forms::Label^ label7;
													private: System::Windows::Forms::LinkLabel^ linkLabel1;

													System::ComponentModel::Container ^components;

            #pragma region Windows Form Designer generated code
														void InitializeComponent(void)
														{
															this->label1 = (gcnew System::Windows::Forms::Label());
															this->label2 = (gcnew System::Windows::Forms::Label());
															this->firstName = (gcnew System::Windows::Forms::TextBox());
															this->email = (gcnew System::Windows::Forms::TextBox());
															this->lastName = (gcnew System::Windows::Forms::TextBox());
															this->label3 = (gcnew System::Windows::Forms::Label());
															this->password = (gcnew System::Windows::Forms::TextBox());
															this->label4 = (gcnew System::Windows::Forms::Label());
															this->button1 = (gcnew System::Windows::Forms::Button());
															this->label7 = (gcnew System::Windows::Forms::Label());
															this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
															this->SuspendLayout();
															// 
															// label1
															// 
															this->label1->AutoSize = true;
															this->label1->Location = System::Drawing::Point(274, 146);
															this->label1->Name = L"label1";
															this->label1->Size = System::Drawing::Size(84, 20);
															this->label1->TabIndex = 0;
															this->label1->Text = L"First name";
															this->label1->Click += gcnew System::EventHandler(this, &SignUp::label1_Click);
															// 
															// label2
															// 
															this->label2->AutoSize = true;
															this->label2->Location = System::Drawing::Point(274, 218);
															this->label2->Name = L"label2";
															this->label2->Size = System::Drawing::Size(46, 20);
															this->label2->TabIndex = 1;
															this->label2->Text = L"Email";
															// 
															// firstName
															// 
															this->firstName->Location = System::Drawing::Point(359, 140);
															this->firstName->Name = L"firstName";
															this->firstName->Size = System::Drawing::Size(142, 26);
															this->firstName->TabIndex = 2;
															// 
															// email
															// 
															this->email->Location = System::Drawing::Point(359, 212);
															this->email->Name = L"email";
															this->email->Size = System::Drawing::Size(365, 26);
															this->email->TabIndex = 3;
															// 
															// lastName
															// 
															this->lastName->Location = System::Drawing::Point(637, 140);
															this->lastName->Name = L"lastName";
															this->lastName->Size = System::Drawing::Size(142, 26);
															this->lastName->TabIndex = 5;
															// 
															// label3
															// 
															this->label3->AutoSize = true;
															this->label3->Location = System::Drawing::Point(552, 146);
															this->label3->Name = L"label3";
															this->label3->Size = System::Drawing::Size(84, 20);
															this->label3->TabIndex = 4;
															this->label3->Text = L"Last name";
															// 
															// password
															// 
															this->password->Location = System::Drawing::Point(359, 279);
															this->password->Name = L"password";
															this->password->Size = System::Drawing::Size(365, 26);
															this->password->TabIndex = 7;
															// 
															// label4
															// 
															this->label4->AutoSize = true;
															this->label4->Location = System::Drawing::Point(275, 285);
															this->label4->Name = L"label4";
															this->label4->Size = System::Drawing::Size(78, 20);
															this->label4->TabIndex = 6;
															this->label4->Text = L"Password";
															// 
															// button1
															// 
															this->button1->Location = System::Drawing::Point(500, 348);
															this->button1->Name = L"button1";
															this->button1->Size = System::Drawing::Size(75, 34);
															this->button1->TabIndex = 12;
															this->button1->Text = L"Sign up";
															this->button1->UseVisualStyleBackColor = true;
															this->button1->Click += gcnew System::EventHandler(this, &SignUp::button1_Click);
															// 
															// label7
															// 
															this->label7->AutoSize = true;
															this->label7->Location = System::Drawing::Point(411, 102);
															this->label7->Name = L"label7";
															this->label7->Size = System::Drawing::Size(192, 20);
															this->label7->TabIndex = 13;
															this->label7->Text = L"Already have an account\?";
															this->label7->Click += gcnew System::EventHandler(this, &SignUp::label7_Click);
															// 
															// linkLabel1
															// 
															this->linkLabel1->AutoSize = true;
															this->linkLabel1->Location = System::Drawing::Point(609, 102);
															this->linkLabel1->Name = L"linkLabel1";
															this->linkLabel1->Size = System::Drawing::Size(48, 20);
															this->linkLabel1->TabIndex = 14;
															this->linkLabel1->TabStop = true;
															this->linkLabel1->Text = L"Login";
															this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SignUp::linkLabel1_LinkClicked);
															// 
															// SignUp
															// 
															this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
															this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
															this->ClientSize = System::Drawing::Size(971, 416);
															this->Controls->Add(this->linkLabel1);
															this->Controls->Add(this->label7);
															this->Controls->Add(this->button1);
															this->Controls->Add(this->password);
															this->Controls->Add(this->label4);
															this->Controls->Add(this->lastName);
															this->Controls->Add(this->label3);
															this->Controls->Add(this->email);
															this->Controls->Add(this->firstName);
															this->Controls->Add(this->label2);
															this->Controls->Add(this->label1);
															this->Name = L"SignUp";
															this->Text = L"SignUp";
															this->Load += gcnew System::EventHandler(this, &SignUp::SignUp_Load);
															this->ResumeLayout(false);
															this->PerformLayout();
														}
            #pragma endregion
													private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
														// Handle login link click event
													}
													private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
														// Handle label click event
													}
													private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
														// Handle label click event
													}
													private: System::Void SignUp_Load(System::Object^ sender, System::EventArgs^ e) {
														// Handle form load event
													}
													private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
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
													};
            }
}
};
}
