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
    /// Summary for ManageFaculty
    /// </summary>
    public ref class ManageFaculty : public System::Windows::Forms::Form
    {
    public:
        ManageFaculty(void)
        {
            InitializeComponent();
            LoadFaculty();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ManageFaculty()
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
    private: System::Windows::Forms::TextBox^ facultyNameTextBox;
    private: System::Windows::Forms::TextBox^ facultyIDTextBox;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;

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
            this->facultyNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->facultyIDTextBox = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
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
            this->addButton->Size = System::Drawing::Size(75, 32);
            this->addButton->TabIndex = 1;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &ManageFaculty::addButton_Click);
            // 
            // updateButton
            // 
            this->updateButton->Location = System::Drawing::Point(93, 400);
            this->updateButton->Name = L"updateButton";
            this->updateButton->Size = System::Drawing::Size(75, 32);
            this->updateButton->TabIndex = 2;
            this->updateButton->Text = L"Update";
            this->updateButton->UseVisualStyleBackColor = true;
            this->updateButton->Click += gcnew System::EventHandler(this, &ManageFaculty::updateButton_Click);
            // 
            // deleteButton
            // 
            this->deleteButton->Location = System::Drawing::Point(174, 400);
            this->deleteButton->Name = L"deleteButton";
            this->deleteButton->Size = System::Drawing::Size(85, 32);
            this->deleteButton->TabIndex = 3;
            this->deleteButton->Text = L"Delete";
            this->deleteButton->UseVisualStyleBackColor = true;
            this->deleteButton->Click += gcnew System::EventHandler(this, &ManageFaculty::deleteButton_Click);
            // 
            // facultyNameTextBox
            // 
            this->facultyNameTextBox->Location = System::Drawing::Point(12, 350);
            this->facultyNameTextBox->Name = L"facultyNameTextBox";
            this->facultyNameTextBox->Size = System::Drawing::Size(237, 26);
            this->facultyNameTextBox->TabIndex = 4;
            // 
            // facultyIDTextBox
            // 
            this->facultyIDTextBox->Location = System::Drawing::Point(255, 350);
            this->facultyIDTextBox->Name = L"facultyIDTextBox";
            this->facultyIDTextBox->Size = System::Drawing::Size(237, 26);
            this->facultyIDTextBox->TabIndex = 5;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 327);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(106, 20);
            this->label1->TabIndex = 6;
            this->label1->Text = L"Faculty Name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(255, 327);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(81, 20);
            this->label2->TabIndex = 7;
            this->label2->Text = L"Faculty ID";
            // 
            // ManageFaculty
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(816, 488);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->facultyIDTextBox);
            this->Controls->Add(this->facultyNameTextBox);
            this->Controls->Add(this->deleteButton);
            this->Controls->Add(this->updateButton);
            this->Controls->Add(this->addButton);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"ManageFaculty";
            this->Text = L"ManageFaculty";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ facultyName = this->facultyNameTextBox->Text;
        int facultyID = Convert::ToInt32(this->facultyIDTextBox->Text);

        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to insert a new faculty member
        String^ query = "INSERT INTO faculty (facultyID, facultyName) VALUES (@FacultyID, @FacultyName)";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);
        command->Parameters->AddWithValue("@FacultyID", facultyID);
        command->Parameters->AddWithValue("@FacultyName", facultyName);

        try
        {
            connection->Open();
            command->ExecuteNonQuery();
            MessageBox::Show("Faculty member added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            LoadFaculty();
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
            int facultyID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["facultyID"]->Value);
            String^ facultyName = this->facultyNameTextBox->Text;

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to update the faculty member
            String^ query = "UPDATE faculty SET facultyName = @FacultyName WHERE facultyID = @FacultyID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@FacultyName", facultyName);
            command->Parameters->AddWithValue("@FacultyID", facultyID);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Faculty member updated successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadFaculty();
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
            MessageBox::Show("Please select a faculty member to update", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridView1->SelectedRows->Count > 0)
        {
            int facultyID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["facultyID"]->Value);

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to delete the faculty member
            String^ query = "DELETE FROM faculty WHERE facultyID = @FacultyID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@FacultyID", facultyID);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Faculty member deleted successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadFaculty();
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
            MessageBox::Show("Please select a faculty member to delete", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: void LoadFaculty()
    {
        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to retrieve the faculty members
        String^ query = "SELECT * FROM faculty";

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

