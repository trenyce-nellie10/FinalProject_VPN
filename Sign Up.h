#pragma once

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ first_name;
	private: System::Windows::Forms::TextBox^ username;


	private: System::Windows::Forms::TextBox^ last_name;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ password1;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ password2;

	private: System::Windows::Forms::Label^ label5;


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
			this->first_name = (gcnew System::Windows::Forms::TextBox());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->last_name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->password1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->password2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(275, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First name";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(275, 165);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Username";
			// 
			// first_name
			// 
			this->first_name->Location = System::Drawing::Point(360, 87);
			this->first_name->Name = L"first_name";
			this->first_name->Size = System::Drawing::Size(142, 26);
			this->first_name->TabIndex = 2;
			// 
			// username
			// 
			this->username->Location = System::Drawing::Point(360, 159);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(365, 26);
			this->username->TabIndex = 3;
			// 
			// last_name
			// 
			this->last_name->Location = System::Drawing::Point(638, 87);
			this->last_name->Name = L"last_name";
			this->last_name->Size = System::Drawing::Size(142, 26);
			this->last_name->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(553, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Last name";
			// 
			// password1
			// 
			this->password1->Location = System::Drawing::Point(360, 226);
			this->password1->Name = L"password1";
			this->password1->Size = System::Drawing::Size(365, 26);
			this->password1->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(276, 232);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Password";
			// 
			// password2
			// 
			this->password2->Location = System::Drawing::Point(360, 286);
			this->password2->Name = L"password2";
			this->password2->Size = System::Drawing::Size(365, 26);
			this->password2->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(220, 289);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(133, 20);
			this->label5->TabIndex = 8;
			this->label5->Text = L"confirm password";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(500, 370);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 34);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Sign up";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(412, 49);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(192, 20);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Already have an account\?";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(610, 49);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(48, 20);
			this->linkLabel1->TabIndex = 14;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Login";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabel1_LinkClicked);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(971, 416);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->password2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->password1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->last_name);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->username);
			this->Controls->Add(this->first_name);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
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
};
}
