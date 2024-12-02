#pragma once

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddGrades
	/// </summary>
	public ref class AddGrades : public System::Windows::Forms::Form
	{
	public:
		AddGrades(void)
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
		~AddGrades()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ studentID;
	protected:

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ courseID;
	private: System::Windows::Forms::TextBox^ grade;


	private: System::Windows::Forms::Label^ label;
	private: System::Windows::Forms::Button^ submit;


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
			this->studentID = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->courseID = (gcnew System::Windows::Forms::Label());
			this->grade = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->submit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(318, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"StudentID";
			this->label1->Click += gcnew System::EventHandler(this, &AddGrades::label1_Click);
			// 
			// studentID
			// 
			this->studentID->Location = System::Drawing::Point(429, 51);
			this->studentID->Name = L"studentID";
			this->studentID->Size = System::Drawing::Size(227, 26);
			this->studentID->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(429, 106);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(227, 26);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &AddGrades::textBox2_TextChanged);
			// 
			// courseID
			// 
			this->courseID->AutoSize = true;
			this->courseID->Location = System::Drawing::Point(324, 112);
			this->courseID->Name = L"courseID";
			this->courseID->Size = System::Drawing::Size(77, 20);
			this->courseID->TabIndex = 2;
			this->courseID->Text = L"CourseID";
			// 
			// grade
			// 
			this->grade->Location = System::Drawing::Point(429, 170);
			this->grade->Name = L"grade";
			this->grade->Size = System::Drawing::Size(227, 26);
			this->grade->TabIndex = 5;
			// 
			// label
			// 
			this->label->AutoSize = true;
			this->label->Location = System::Drawing::Point(347, 173);
			this->label->Name = L"label";
			this->label->Size = System::Drawing::Size(54, 20);
			this->label->TabIndex = 4;
			this->label->Text = L"Grade";
			// 
			// submit
			// 
			this->submit->Location = System::Drawing::Point(499, 239);
			this->submit->Name = L"submit";
			this->submit->Size = System::Drawing::Size(75, 29);
			this->submit->TabIndex = 6;
			this->submit->Text = L"submit";
			this->submit->UseVisualStyleBackColor = true;
			// 
			// AddGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(915, 335);
			this->Controls->Add(this->submit);
			this->Controls->Add(this->grade);
			this->Controls->Add(this->label);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->courseID);
			this->Controls->Add(this->studentID);
			this->Controls->Add(this->label1);
			this->Name = L"AddGrades";
			this->Text = L"AddGrades";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
