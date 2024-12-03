#pragma once

namespace FinalProjectVPN {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class ManageFaculty : public System::Windows::Forms::Form
    {
    public:
        ManageFaculty(void)
        {
            InitializeComponent();
            LoadFaculty();
        }

    protected:
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
    private: System::Windows::Forms::TextBox^ emailTextBox;
    private: System::Windows::Forms::TextBox^ passwordTextBox;
    private: System::Windows::Forms::TextBox^ departmentTextBox;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;

    protected:

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->addButton = (gcnew System::Windows::Forms::Button());
            this->updateButton = (gcnew System::Windows::Forms::Button());
            this->deleteButton = (gcnew System::Windows::Forms::Button());
            this->facultyNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->facultyIDTextBox = (gcnew System::Windows::Forms::TextBox());
            this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
            this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
            this->departmentTextBox = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
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
            this->addButton->Location = System::Drawing::Point(12, 500);
            this->addButton->Name = L"addButton";
            this->addButton->Size = System::Drawing::Size(75, 32);
            this->addButton->TabIndex = 1;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &ManageFaculty::addButton_Click);
            // 
            // updateButton
            // 
            this->updateButton->Location = System::Drawing::Point(93, 500);
            this->updateButton->Name = L"updateButton";
            this->updateButton->Size = System::Drawing::Size(75, 32);
            this->updateButton->TabIndex = 2;
            this->updateButton->Text = L"Update";
            this->updateButton->UseVisualStyleBackColor = true;
            this->updateButton->Click += gcnew System::EventHandler(this, &ManageFaculty::updateButton_Click);
            // 
            // deleteButton
            // 
            this->deleteButton->Location = System::Drawing::Point(174, 500);
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
            // emailTextBox
            // 
            this->emailTextBox->Location = System::Drawing::Point(498, 350);
            this->emailTextBox->Name = L"emailTextBox";
            this->emailTextBox->Size = System::Drawing::Size(237, 26);
            this->emailTextBox->TabIndex = 6;
            // 
            // passwordTextBox
            // 
            this->passwordTextBox->Location = System::Drawing::Point(12, 400);
            this->passwordTextBox->Name = L"passwordTextBox";
            this->passwordTextBox->Size = System::Drawing::Size(237, 26);
            this->passwordTextBox->TabIndex = 7;
            // 
            // departmentTextBox
            // 
            this->departmentTextBox->Location = System::Drawing::Point(255, 400);
            this->departmentTextBox->Name = L"departmentTextBox";
            this->departmentTextBox->Size = System::Drawing::Size(237, 26);
            this->departmentTextBox->TabIndex = 8;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 327);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(106, 20);
            this->label1->TabIndex = 9;
            this->label1->Text = L"Faculty Name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(255, 327);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(81, 20);
            this->label2->TabIndex = 10;
            this->label2->Text = L"Faculty ID";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(498, 327);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(48, 20);
            this->label3->TabIndex = 11;
            this->label3->Text = L"Email";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(12, 377);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(78, 20);
            this->label4->TabIndex = 12;
            this->label4->Text = L"Password";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(255, 377);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(94, 20);
            this->label5->TabIndex = 13;
            this->label5->Text = L"Department";
            // 
            // ManageFaculty
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(816, 550);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->departmentTextBox);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->emailTextBox);
            this->Controls->Add(this->passwordTextBox);
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
        String^ email = this->emailTextBox->Text;
        String^ password = this->passwordTextBox->Text;
        String^ department = this->departmentTextBox->Text;

        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to insert a new user and faculty member
        String^ query = "INSERT INTO users (userID, firstName, email, password) VALUES (@UserID, @FirstName, @Email, @Password); " +
            "INSERT INTO faculty (facultyID, userID, department) VALUES (@FacultyID, @UserID, @Department)";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);
        command->Parameters->AddWithValue("@UserID", facultyID);
        command->Parameters->AddWithValue("@FirstName", facultyName);
        command->Parameters->AddWithValue("@Email", email);
        command->Parameters->AddWithValue("@Password", password);
        command->Parameters->AddWithValue("@FacultyID", facultyID);
        command->Parameters->AddWithValue("@Department", department);

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
            String^ email = this->emailTextBox->Text;
            String^ password = this->passwordTextBox->Text;
            String^ department = this->departmentTextBox->Text;

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to update the user and faculty member
            String^ query = "UPDATE users SET firstName = @FirstName, email = @Email, password = @Password WHERE userID = @UserID; " +
                "UPDATE faculty SET facultyID = @FacultyID, department = @Department WHERE userID = @UserID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@UserID", facultyID);
            command->Parameters->AddWithValue("@FirstName", facultyName);
            command->Parameters->AddWithValue("@Email", email);
            command->Parameters->AddWithValue("@Password", password);
            command->Parameters->AddWithValue("@FacultyID", facultyID);
            command->Parameters->AddWithValue("@Department", department);

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

            // SQL query to delete the user and faculty member
            String^ query = "DELETE FROM faculty WHERE facultyID = @FacultyID; " +
                "DELETE FROM users WHERE userID = @UserID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@FacultyID", facultyID);
            command->Parameters->AddWithValue("@UserID", facultyID);

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

        // SQL query to retrieve the faculty members with their full name, email, password, and department
        String^ query = "SELECT faculty.facultyID, users.firstName, users.email, users.password, faculty.department " +
            "FROM faculty " +
            "INNER JOIN users ON faculty.userID = users.userID";

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

