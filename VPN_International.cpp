#include "VPN_International.h"
using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FinalProjectVPN::VPN_International form;  // Potential issue here
    Application::Run(% form);
}

using namespace MySql::Data::MySqlClient;
public ref class MyForm : public System::Windows::Forms::Form {
    MySqlConnection^ sqlConn = gcnew MySqlConnection();
    MySqlCommand^ sqlCmd = gcnew MySqlCommand();
    DataTable^ sqlDt = gcnew DataTable();
    MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();

public:
    MySqlDataReader^ sqlRd;

    sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=ashesi";
    sqlConn->Open();
    sqlCmd->Connection = sqlConn;
    sqlCmd->CommandText = "SELECT * FROM employee";
    sqlRd = sqlCmd->ExecuteReader();
    sqlDt->Load(sqlRd);
    sqlRd->Close();
    sqlConn->Close();
    dataGridView1->DataSource = sqlDt;



};
