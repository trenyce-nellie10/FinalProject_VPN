#include "ChildForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

void ChildForm::InitializeComponent() {
    this->dataGridView1 = gcnew DataGridView();
    this->Controls->Add(this->dataGridView1);
    this->Text = L"Child Form";
    this->Load += gcnew EventHandler(this, &ChildForm::ChildForm_Load);
}

void ChildForm::ChildForm_Load(Object^ sender, EventArgs^ e) {
    MySqlConnection^ sqlConn = gcnew MySqlConnection("datasource=localhost;port=3306;username=root;password=;database=university");
    MySqlCommand^ sqlCmd = gcnew MySqlCommand("SELECT * FROM students", sqlConn);
    MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter(sqlCmd);
    DataTable^ sqlDt = gcnew DataTable();
    sqlDtA->Fill(sqlDt);
    this->dataGridView1->DataSource = sqlDt;
}