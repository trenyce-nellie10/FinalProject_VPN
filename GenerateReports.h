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
    /// Summary for GenerateReports
    /// </summary>
    public ref class GenerateReports : public System::Windows::Forms::Form
    {
    public:
        GenerateReports(void)
        {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~GenerateReports()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ studentReportButton;
    private: System::Windows::Forms::Button^ courseReportButton;
    private: System::Windows::Forms::Button^ financialReportButton;
    private: System::Windows::Forms::DataGridView^ dataGridView1;

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->studentReportButton = (gcnew System::Windows::Forms::Button());
            this->courseReportButton = (gcnew System::Windows::Forms::Button());
            this->financialReportButton = (gcnew System::Windows::Forms::Button());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // studentReportButton
            // 
            this->studentReportButton->Location = System::Drawing::Point(12, 12);
            this->studentReportButton->Name = L"studentReportButton";
            this->studentReportButton->Size = System::Drawing::Size(150, 30);
            this->studentReportButton->TabIndex = 0;
            this->studentReportButton->Text = L"Student Report";
            this->studentReportButton->UseVisualStyleBackColor = true;
            this->studentReportButton->Click += gcnew System::EventHandler(this, &GenerateReports::studentReportButton_Click);
            // 
            // courseReportButton
            // 
            this->courseReportButton->Location = System::Drawing::Point(168, 12);
            this->courseReportButton->Name = L"courseReportButton";
            this->courseReportButton->Size = System::Drawing::Size(150, 30);
            this->courseReportButton->TabIndex = 1;
            this->courseReportButton->Text = L"Course Report";
            this->courseReportButton->UseVisualStyleBackColor = true;
            this->courseReportButton->Click += gcnew System::EventHandler(this, &GenerateReports::courseReportButton_Click);
            // 
            // financialReportButton
            // 
            this->financialReportButton->Location = System::Drawing::Point(324, 12);
            this->financialReportButton->Name = L"financialReportButton";
            this->financialReportButton->Size = System::Drawing::Size(150, 30);
            this->financialReportButton->TabIndex = 2;
            this->financialReportButton->Text = L"Financial Report";
            this->financialReportButton->UseVisualStyleBackColor = true;
            this->financialReportButton->Click += gcnew System::EventHandler(this, &GenerateReports::financialReportButton_Click);
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(12, 60);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 62;
            this->dataGridView1->RowTemplate->Height = 28;
            this->dataGridView1->Size = System::Drawing::Size(776, 378);
            this->dataGridView1->TabIndex = 3;
            // 
            // GenerateReports
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 450);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->financialReportButton);
            this->Controls->Add(this->courseReportButton);
            this->Controls->Add(this->studentReportButton);
            this->Name = L"GenerateReports";
            this->Text = L"GenerateReports";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void studentReportButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to retrieve student report
        String^ query = "SELECT * FROM student";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);

        try
        {
            connection->Open();

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

    private: System::Void courseReportButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to retrieve course report
        String^ query = "SELECT * FROM course";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);

        try
        {
            connection->Open();

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

    private: System::Void financialReportButton_Click(System::Object^ sender, System::EventArgs^ e) {
        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to retrieve financial report
        String^ query = "SELECT * FROM payments";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);

        try
        {
            connection->Open();

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

