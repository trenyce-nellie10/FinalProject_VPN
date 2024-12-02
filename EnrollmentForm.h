#pragma once

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for EnrollmentForm
	/// </summary>
	public ref class EnrollmentForm : public System::Windows::Forms::Form
	{
	public:
		EnrollmentForm(void)
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
		~EnrollmentForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ name;
	private: System::Windows::Forms::TextBox^ StudentID;
	private: System::Windows::Forms::Button^ Submit_button;



	private: System::Windows::Forms::ComboBox^ CoursesComboBox;

	private: System::Windows::Forms::Label^ label3;

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
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->StudentID = (gcnew System::Windows::Forms::TextBox());
			this->Submit_button = (gcnew System::Windows::Forms::Button());
			this->CoursesComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(92, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(92, 169);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Student ID";
			// 
			// name
			// 
			this->name->Location = System::Drawing::Point(264, 89);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(117, 26);
			this->name->TabIndex = 2;
			this->name->TextChanged += gcnew System::EventHandler(this, &EnrollmentForm::textBox1_TextChanged);
			// 
			// StudentID
			// 
			this->StudentID->Location = System::Drawing::Point(264, 169);
			this->StudentID->Name = L"StudentID";
			this->StudentID->Size = System::Drawing::Size(117, 26);
			this->StudentID->TabIndex = 3;
			// 
			// Submit_button
			// 
			this->Submit_button->Location = System::Drawing::Point(281, 433);
			this->Submit_button->Name = L"Submit_button";
			this->Submit_button->Size = System::Drawing::Size(100, 37);
			this->Submit_button->TabIndex = 4;
			this->Submit_button->Text = L"Submit ";
			this->Submit_button->UseVisualStyleBackColor = true;
			this->Submit_button->Click += gcnew System::EventHandler(this, &EnrollmentForm::Submit_button_Click);
			// 
			// CoursesComboBox
			// 
			this->CoursesComboBox->FormattingEnabled = true;
			this->CoursesComboBox->Location = System::Drawing::Point(260, 283);
			this->CoursesComboBox->Name = L"CoursesComboBox";
			this->CoursesComboBox->Size = System::Drawing::Size(121, 28);
			this->CoursesComboBox->TabIndex = 5;
			this->CoursesComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &EnrollmentForm::comboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(92, 283);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Course";
			// 
			// EnrollmentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1361, 608);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->CoursesComboBox);
			this->Controls->Add(this->Submit_button);
			this->Controls->Add(this->StudentID);
			this->Controls->Add(this->name);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"EnrollmentForm";
			this->Text = L"EnrollmentForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Submit_button_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ name = this->name->Text;
	String^ studentID = this->StudentID->Text;
	String^ course = this->CoursesComboBox->SelectedItem->ToString();

	// Database connection string
	String^ connectionString = "Data Source=your_server_name;Initial Catalog=your_database_name;Integrated Security=True";

	// SQL query to insert the enrollment details
	String^ query = "INSERT INTO Students (StudentID, Name, Course) VALUES (@StudentID, @Name, @Course)";

	// Create a connection to the database
	MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
	MySqlCommand^ command = gcnew MySqlCommand(query, connection);

	// Add parameters to the SQL query
	command->Parameters->AddWithValue("@StudentID", studentID);
	command->Parameters->AddWithValue("@Name", name);
	command->Parameters->AddWithValue("@Course", course);

	try
	{
		// Open the connection
		connection->Open();

		// Execute the query
		command->ExecuteNonQuery();

		// Show a success message
		MessageBox::Show("Student Enrolled Successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex)
	{
		// Show an error message
		MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally
	{
		// Close the connection
		connection->Close();
	}

	this->Close();
}
};
}

