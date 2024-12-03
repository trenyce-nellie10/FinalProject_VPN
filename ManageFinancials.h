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
    /// Summary for ManageFinancials
    /// </summary>
    public ref class ManageFinancials : public System::Windows::Forms::Form
    {
    public:
        ManageFinancials(void)
        {
            InitializeComponent();
            LoadFinancials();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ManageFinancials()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Button^ addButton;
    private: System::Windows::Forms::Button^ updateButton;
    private: System::Windows::Forms::Button^ deleteButton;
    private: System::Windows::Forms::TextBox^ transactionIDTextBox;
    private: System::Windows::Forms::TextBox^ amountTextBox;
    private: System::Windows::Forms::TextBox^ descriptionTextBox;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;

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
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->addButton = (gcnew System::Windows::Forms::Button());
            this->updateButton = (gcnew System::Windows::Forms::Button());
            this->deleteButton = (gcnew System::Windows::Forms::Button());
            this->transactionIDTextBox = (gcnew System::Windows::Forms::TextBox());
            this->amountTextBox = (gcnew System::Windows::Forms::TextBox());
            this->descriptionTextBox = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(12, 12);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->RowHeadersWidth = 62;
            this->dataGridView1->RowTemplate->Height = 28;
            this->dataGridView1->Size = System::Drawing::Size(776, 300);
            this->dataGridView1->TabIndex = 0;
            // 
            // addButton
            // 
            this->addButton->Location = System::Drawing::Point(12, 400);
            this->addButton->Name = L"addButton";
            this->addButton->Size = System::Drawing::Size(75, 23);
            this->addButton->TabIndex = 1;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &ManageFinancials::addButton_Click);
            // 
            // updateButton
            // 
            this->updateButton->Location = System::Drawing::Point(93, 400);
            this->updateButton->Name = L"updateButton";
            this->updateButton->Size = System::Drawing::Size(75, 23);
            this->updateButton->TabIndex = 2;
            this->updateButton->Text = L"Update";
            this->updateButton->UseVisualStyleBackColor = true;
            this->updateButton->Click += gcnew System::EventHandler(this, &ManageFinancials::updateButton_Click);
            // 
            // deleteButton
            // 
            this->deleteButton->Location = System::Drawing::Point(174, 400);
            this->deleteButton->Name = L"deleteButton";
            this->deleteButton->Size = System::Drawing::Size(75, 23);
            this->deleteButton->TabIndex = 3;
            this->deleteButton->Text = L"Delete";
            this->deleteButton->UseVisualStyleBackColor = true;
            this->deleteButton->Click += gcnew System::EventHandler(this, &ManageFinancials::deleteButton_Click);
            // 
            // transactionIDTextBox
            // 
            this->transactionIDTextBox->Location = System::Drawing::Point(16, 350);
            this->transactionIDTextBox->Name = L"transactionIDTextBox";
            this->transactionIDTextBox->Size = System::Drawing::Size(100, 26);
            this->transactionIDTextBox->TabIndex = 4;
            // 
            // amountTextBox
            // 
            this->amountTextBox->Location = System::Drawing::Point(132, 350);
            this->amountTextBox->Name = L"amountTextBox";
            this->amountTextBox->Size = System::Drawing::Size(100, 26);
            this->amountTextBox->TabIndex = 5;
            // 
            // descriptionTextBox
            // 
            this->descriptionTextBox->Location = System::Drawing::Point(251, 350);
            this->descriptionTextBox->Name = L"descriptionTextBox";
            this->descriptionTextBox->Size = System::Drawing::Size(237, 26);
            this->descriptionTextBox->TabIndex = 6;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 327);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(113, 20);
            this->label1->TabIndex = 7;
            this->label1->Text = L"Transaction ID";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(128, 327);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(65, 20);
            this->label2->TabIndex = 8;
            this->label2->Text = L"Amount";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(224, 327);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(89, 20);
            this->label3->TabIndex = 9;
            this->label3->Text = L"Description";
            // 
            // ManageFinancials
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 450);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->descriptionTextBox);
            this->Controls->Add(this->amountTextBox);
            this->Controls->Add(this->transactionIDTextBox);
            this->Controls->Add(this->deleteButton);
            this->Controls->Add(this->updateButton);
            this->Controls->Add(this->addButton);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"ManageFinancials";
            this->Text = L"ManageFinancials";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
        int transactionID = Convert::ToInt32(this->transactionIDTextBox->Text);
        double amount = Convert::ToDouble(this->amountTextBox->Text);
        String^ description = this->descriptionTextBox->Text;

        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to insert a new financial transaction
        String^ query = "INSERT INTO financials (transactionID, amount, description) VALUES (@TransactionID, @Amount, @Description)";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);
        command->Parameters->AddWithValue("@TransactionID", transactionID);
        command->Parameters->AddWithValue("@Amount", amount);
        command->Parameters->AddWithValue("@Description", description);

        try
        {
            connection->Open();
            command->ExecuteNonQuery();
            MessageBox::Show("Transaction added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            LoadFinancials();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally
        {
            connection->Close();
        }
    }

    private: System::Void updateButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridView1->SelectedRows->Count > 0)
        {
            int transactionID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["transactionID"]->Value);
            double amount = Convert::ToDouble(this->amountTextBox->Text);
            String^ description = this->descriptionTextBox->Text;

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to update the financial transaction
            String^ query = "UPDATE financials SET amount = @Amount, description = @Description WHERE transactionID = @TransactionID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@TransactionID", transactionID);
            command->Parameters->AddWithValue("@Amount", amount);
            command->Parameters->AddWithValue("@Description", description);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Transaction updated successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadFinancials();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally
            {
                connection->Close();
            }
        }
        else
        {
            MessageBox::Show("Please select a transaction to update", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridView1->SelectedRows->Count > 0)
        {
            int transactionID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["transactionID"]->Value);

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to delete the financial transaction
            String^ query = "DELETE FROM financials WHERE transactionID = @TransactionID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@TransactionID", transactionID);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Transaction deleted successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadFinancials();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally
            {
                connection->Close();
            }
        }
        else
        {
            MessageBox::Show("Please select a transaction to delete", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: void LoadFinancials()
    {
        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to retrieve the financial transactions
        String^ query = "SELECT * FROM financials";

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

