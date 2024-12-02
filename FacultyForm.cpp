#include "FacultyForm.h"
#include "Enrollment.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

void FacultyForm::InitializeComponent() {
    this->dataGridView1 = gcnew DataGridView();
    this->verifyButton = gcnew Button();

    this->verifyButton->Text = L"Verify Enrollment";
    this->verifyButton->Click += gcnew EventHandler(this, &FacultyForm::verifyButton_Click);

    this->Controls->Add(this->dataGridView1);
    this->Controls->Add(this->verifyButton);

    this->Text = L"Faculty Enrollment Verification";
    this->Load += gcnew EventHandler(this, &FacultyForm::FacultyForm_Load);
}

void FacultyForm::FacultyForm_Load(Object^ sender, EventArgs^ e) {
    // Load enrollments for verification
    MySqlConnection^ sqlConn = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=;database=university");
    MySqlCommand^ sqlCmd = gcnew MySqlCommand("SELECT * FROM enrollment WHERE verified = 0", sqlConn);
    MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter(sqlCmd);
    DataTable^ sqlDt = gcnew DataTable();
    sqlDtA->Fill(sqlDt);
    this->dataGridView1->DataSource = sqlDt;
}

void FacultyForm::verifyButton_Click(Object^ sender, EventArgs^ e) {
    // Verify selected enrollment
    if (this->dataGridView1->SelectedRows->Count > 0) {
        String^ enrollmentID = this->dataGridView1->SelectedRows[0]->Cells["enrollmentID"]->Value->ToString();

        MySqlConnection^ sqlConn = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=;database=university");
        MySqlCommand^ sqlCmd = gcnew MySqlCommand("UPDATE enrollments SET verified = 1 WHERE enrollmentID = @enrollmentID", sqlConn);
        sqlCmd->Parameters->AddWithValue("@enrollmentID", enrollmentID);

        sqlConn->Open();
        sqlCmd->ExecuteNonQuery();
        sqlConn->Close();

        MessageBox::Show("Enrollment verified successfully!");
    }
}
