#include "StudentForm.h"
#include "Course.h"
#include "Enrollment.h"
#include <vector>

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;
using namespace std;

void StudentForm::InitializeComponent() {
    this->dataGridView1 = gcnew DataGridView();
    this->enrollButton = gcnew Button();
    this->searchTextBox = gcnew TextBox();

    this->enrollButton->Text = L"Enroll";
    this->enrollButton->Click += gcnew EventHandler(this, &StudentForm::enrollButton_Click);

    this->searchTextBox->TextChanged += gcnew EventHandler(this, &StudentForm::searchTextBox_TextChanged);

    this->Controls->Add(this->dataGridView1);
    this->Controls->Add(this->enrollButton);
    this->Controls->Add(this->searchTextBox);

    this->Text = L"Student Enrollment";
    this->Load += gcnew EventHandler(this, &StudentForm::StudentForm_Load);
}

void StudentForm::StudentForm_Load(Object^ sender, EventArgs^ e) {
    // Load available courses
    MySqlConnection^ sqlConn = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=;database=university");
    MySqlCommand^ sqlCmd = gcnew MySqlCommand("SELECT * FROM courses", sqlConn);
    MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter(sqlCmd);
    DataTable^ sqlDt = gcnew DataTable();
    sqlDtA->Fill(sqlDt);
    this->dataGridView1->DataSource = sqlDt;
}

void StudentForm::enrollButton_Click(Object^ sender, EventArgs^ e) {
    // Enroll in selected course
    if (this->dataGridView1->SelectedRows->Count > 0) {
        String^ courseID = this->dataGridView1->SelectedRows[0]->Cells["courseID"]->Value->ToString();
        String^ studentID = "12345"; // Replace with actual student ID

        MySqlConnection^ sqlConn = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=;database=university");
        MySqlCommand^ sqlCmd = gcnew MySqlCommand("INSERT INTO enrollments (studentID, courseID, semester) VALUES (@studentID, @courseID, 'Fall 2023')", sqlConn);
        sqlCmd->Parameters->AddWithValue("@studentID", studentID);
        sqlCmd->Parameters->AddWithValue("@courseID", courseID);

        sqlConn->Open();
        sqlCmd->ExecuteNonQuery();
        sqlConn->Close();

        MessageBox::Show("Enrolled successfully!");
    }
}

void StudentForm::searchTextBox_TextChanged(Object^ sender, EventArgs^ e) {
    // Search for courses
    String^ searchText = this->searchTextBox->Text;
    MySqlConnection^ sqlConn = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=;database=university");
    MySqlCommand^ sqlCmd = gcnew MySqlCommand("SELECT * FROM courses WHERE courseName LIKE @searchText", sqlConn);
    sqlCmd->Parameters->AddWithValue("@searchText", "%" + searchText + "%");
    MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter(sqlCmd);
    DataTable^ sqlDt = gcnew DataTable();
    sqlDtA->Fill(sqlDt);
    this->dataGridView1->DataSource = sqlDt;
}