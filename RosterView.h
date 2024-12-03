#pragma once

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class RosterView : public System::Windows::Forms::Form
	{
	public:
		RosterView(int facultyUserID)
		{
			InitializeComponent();
			this->facultyUserID = facultyUserID;
			LoadRoster();
		}

	protected:
		~RosterView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ courseID;
	private: System::Windows::Forms::Button^ getRoster;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: int facultyUserID;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->courseID = (gcnew System::Windows::Forms::TextBox());
			this->getRoster = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(168, 145);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"courseID";
			// 
			// courseID
			// 
			this->courseID->Location = System::Drawing::Point(268, 139);
			this->courseID->Name = L"courseID";
			this->courseID->Size = System::Drawing::Size(212, 26);
			this->courseID->TabIndex = 1;
			// 
			// getRoster
			// 
			this->getRoster->Location = System::Drawing::Point(286, 219);
			this->getRoster->Name = L"getRoster";
			this->getRoster->Size = System::Drawing::Size(147, 27);
			this->getRoster->TabIndex = 2;
			this->getRoster->Text = L"Get Roster";
			this->getRoster->UseVisualStyleBackColor = true;
			this->getRoster->Click += gcnew System::EventHandler(this, &RosterView::getRoster_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(776, 300);
			this->dataGridView1->TabIndex = 3;
			// 
			// RosterView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 450);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->getRoster);
			this->Controls->Add(this->courseID);
			this->Controls->Add(this->label1);
			this->Name = L"RosterView";
			this->Text = L"RosterView";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void getRoster_Click(System::Object^ sender, System::EventArgs^ e) {
		LoadRoster();
	}

	private: void LoadRoster() {
		// Database connection string
		String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

		// SQL query to get the department of the faculty member
		String^ query = "SELECT department FROM faculty WHERE userID = @FacultyUserID";

		// Create a connection to the database
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		MySqlCommand^ command = gcnew MySqlCommand(query, connection);
		command->Parameters->AddWithValue("@FacultyUserID", facultyUserID);

		try
		{
			connection->Open();
			String^ department = (String^)command->ExecuteScalar();

			// SQL query to get the courseID for the department
			query = "SELECT courseID FROM course WHERE courseName = @Department";
			command = gcnew MySqlCommand(query, connection);
			command->Parameters->AddWithValue("@Department", department);
			int courseID = Convert::ToInt32(command->ExecuteScalar());

			// SQL query to get the students enrolled in the course
			query = "SELECT student.studentID, users.firstName, users.lastName " +
				"FROM enrollments " +
				"INNER JOIN student ON enrollments.studentID = student.studentID " +
				"INNER JOIN users ON student.userID = users.userID " +
				"WHERE enrollments.courseID = @CourseID";
			command = gcnew MySqlCommand(query, connection);
			command->Parameters->AddWithValue("@CourseID", courseID);

			// Execute the query and load the data into a DataTable
			MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(command);
			DataTable^ dataTable = gcnew DataTable();
			adapter->Fill(dataTable);

			// Bind the DataTable to the DataGridView
			dataGridView1->DataSource = dataTable;
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
	}
	};
}

