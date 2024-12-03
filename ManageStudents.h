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
    /// Summary for ManageStudents
    /// </summary>
    public ref class ManageStudents : public System::Windows::Forms::Form
    {
    public:
        ManageStudents(void)
        {
            InitializeComponent();
            LoadStudents();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ManageStudents()
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
    private: System::Windows::Forms::TextBox^ studentNameTextBox;
    private: System::Windows::Forms::TextBox^ studentIDTextBox;
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
            this->studentNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->studentIDTextBox = (gcnew System::Windows::Forms::TextBox());
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
            this->addButton->Size = System::Drawing::Size(75, 38);
            this->addButton->TabIndex = 1;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &ManageStudents::addButton_Click);
            // 
            // updateButton
            // 
            this->updateButton->Location = System::Drawing::Point(93, 400);
            this->updateButton->Name = L"updateButton";
            this->updateButton->Size = System::Drawing::Size(75, 38);
            this->updateButton->TabIndex = 2;
            this->updateButton->Text = L"Update";
            this->updateButton->UseVisualStyleBackColor = true;
            this->updateButton->Click += gcnew System::EventHandler(this, &ManageStudents::updateButton_Click);
            // 
            // deleteButton
            // 
            this->deleteButton->Location = System::Drawing::Point(174, 400);
            this->deleteButton->Name = L"deleteButton";
            this->deleteButton->Size = System::Drawing::Size(75, 38);
            this->deleteButton->TabIndex = 3;
            this->deleteButton->Text = L"Delete";
            this->deleteButton->UseVisualStyleBackColor = true;
            this->deleteButton->Click += gcnew System::EventHandler(this, &ManageStudents::deleteButton_Click);
            // 
            // studentNameTextBox
            // 
            this->studentNameTextBox->Location = System::Drawing::Point(12, 350);
            this->studentNameTextBox->Name = L"studentNameTextBox";
            this->studentNameTextBox->Size = System::Drawing::Size(237, 26);
            this->studentNameTextBox->TabIndex = 4;
            // 
            // studentIDTextBox
            // 
            this->studentIDTextBox->Location = System::Drawing::Point(255, 350);
            this->studentIDTextBox->Name = L"studentIDTextBox";
            this->studentIDTextBox->Size = System::Drawing::Size(237, 26);
            this->studentIDTextBox->TabIndex = 5;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 327);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(106, 20);
            this->label1->TabIndex = 6;
            this->label1->Text = L"Student Name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(255, 327);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(87, 20);
            this->label2->TabIndex = 7;
            this->label2->Text = L"Student ID";
            // 
            // ManageStudents
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 450);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->studentIDTextBox);
            this->Controls->Add(this->studentNameTextBox);
            this->Controls->Add(this->deleteButton);
            this->Controls->Add(this->updateButton);
            this->Controls->Add(this->addButton);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"ManageStudents";
            this->Text = L"ManageStudents";
            this->Load += gcnew System::EventHandler(this, &ManageStudents::ManageStudents_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ studentName = this->studentNameTextBox->Text;
        int studentID = Convert::ToInt32(this->studentIDTextBox->Text);

        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to insert a new student
        String^ query = "INSERT INTO student (studentID, studentName) VALUES (@StudentID, @StudentName)";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);
        command->Parameters->AddWithValue("@StudentID", studentID);
        command->Parameters->AddWithValue("@StudentName", studentName);

        try
        {
            connection->Open();
            command->ExecuteNonQuery();
            MessageBox::Show("Student added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            LoadStudents();
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
            int studentID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["studentID"]->Value);
            String^ studentName = this->studentNameTextBox->Text;

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to update the student
            String^ query = "UPDATE student SET studentName = @StudentName WHERE studentID = @StudentID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@StudentName", studentName);
            command->Parameters->AddWithValue("@StudentID", studentID);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Student updated successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadStudents();
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
            MessageBox::Show("Please select a student to update", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridView1->SelectedRows->Count > 0)
        {
            int studentID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["studentID"]->Value);

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to delete the student
            String^ query = "DELETE FROM student WHERE studentID = @StudentID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@StudentID", studentID);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Student deleted successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadStudents();
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
            MessageBox::Show("Please select a student to delete", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: void LoadStudents()
    {
        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to retrieve the students
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
    private: System::Void ManageStudents_Load(System::Object^ sender, System::EventArgs^ e) {
    }
};
}

