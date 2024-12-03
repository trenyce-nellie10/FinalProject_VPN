#pragma once

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class ViewGrades : public System::Windows::Forms::Form {
	private:
		int userID;
		int userRole;
		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		MySqlDataReader^ sqlRd;

	public:
		ViewGrades(int userId, int userRole) {
			this->userID = userId;
			this->userRole = userRole;
			InitializeComponent();
		}

	protected:
		~ViewGrades() {
			if (components) {
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::DataGridView^ dataGridView1;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(30, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(115, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Grades";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(400, 20);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 30);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Retrieve";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ViewGrades::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(30, 70);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(500, 300);
			this->dataGridView1->TabIndex = 2;
			// 
			// ViewGrades
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 400);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"ViewGrades";
			this->Text = L"View Grades";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private:
		void LoadUserGrades() {
			try {
				String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";
				sqlConn = gcnew MySqlConnection(connectionString);
				sqlConn->Open();

				// Step 1: Get studentID using the userID
				String^ studentQuery = "SELECT studentID FROM student WHERE userID = @userID";

				sqlCmd = gcnew MySqlCommand(studentQuery, sqlConn);
				sqlCmd->Parameters->AddWithValue("@userID", this->userID);
				sqlRd = sqlCmd->ExecuteReader();

				if (sqlRd->Read()) {
					// Assuming studentID is in the first column of the result
					int studentID = sqlRd->GetInt32(0);
					sqlRd->Close(); // Close the reader

					// Step 2: Now use studentID to fetch grades
					String^ query = "SELECT c.courseName AS 'Course', g.grade AS 'Grade' "
						"FROM grades g "
						"JOIN course c ON g.courseID = c.courseID "
						"WHERE g.studentID = @studentID";

					sqlCmd = gcnew MySqlCommand(query, sqlConn);
					sqlCmd->Parameters->AddWithValue("@studentID", studentID);
					sqlRd = sqlCmd->ExecuteReader();

					DataTable^ dt = gcnew DataTable();
					dt->Load(sqlRd);
					dataGridView1->DataSource = dt;
				}
				else {
					MessageBox::Show("UserID not found in the database: " + this->userID);
				}

				sqlConn->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}


		void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			LoadUserGrades();
		}
	};
}
