#include "VPN_International.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient; // Correct namespace for MySQL
using namespace System::Data; // Add this line to include the DataTable class

int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FinalProjectVPN::VPN_International form;
    Application::Run(% form);
}

public ref class MyForm : public System::Windows::Forms::Form {
    MySqlConnection^ sqlConn = gcnew MySqlConnection();
    MySqlCommand^ sqlCmd = gcnew MySqlCommand();
    DataTable^ sqlDt = gcnew DataTable(); // This line now works correctly
    MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();

public:
    MySqlDataReader^ sqlRd;

    MyForm() {
        InitializeComponent();
        sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=university";
        sqlConn->Open();
        sqlCmd->Connection = sqlConn;
        sqlCmd->CommandText = "SELECT * FROM users";
        sqlRd = sqlCmd->ExecuteReader();
        sqlDt->Load(sqlRd);
        sqlRd->Close();
        sqlConn->Close();
        /*dataGridView1->DataSource = sqlDt;*/
    }

private:
    void InitializeComponent() {
        // Initialize your form components here
    }
};
