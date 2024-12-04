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
    private: System::Windows::Forms::TextBox^ firstNameTextBox;
    private: System::Windows::Forms::TextBox^ lastNameTextBox;
    private: System::Windows::Forms::TextBox^ studentIDTextBox;
    private: System::Windows::Forms::TextBox^ majorTextBox;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;

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
            this->firstNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->lastNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->studentIDTextBox = (gcnew System::Windows::Forms::TextBox());
            this->majorTextBox = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
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
            this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView1->MultiSelect = false;
            this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &ManageStudents::dataGridView1_CellClick);
            // 
            // addButton
            // 
            this->addButton->Location = System::Drawing::Point(12, 450);
            this->addButton->Name = L"addButton";
            this->addButton->Size = System::Drawing::Size(75, 38);
            this->addButton->TabIndex = 1;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &ManageStudents::addButton_Click);
            // 
            // updateButton
            // 
            this->updateButton->Location = System::Drawing::Point(93, 450);
            this->updateButton->Name = L"updateButton";
            this->updateButton->Size = System::Drawing::Size(75, 38);
            this->updateButton->TabIndex = 2;
            this->updateButton->Text = L"Update";
            this->updateButton->UseVisualStyleBackColor = true;
            this->updateButton->Click += gcnew System::EventHandler(this, &ManageStudents::updateButton_Click);
            // 
            // deleteButton
            // 
            this->deleteButton->Location = System::Drawing::Point(174, 450);
            this->deleteButton->Name = L"deleteButton";
            this->deleteButton->Size = System::Drawing::Size(75, 38);
            this->deleteButton->TabIndex = 3;
            this->deleteButton->Text = L"Delete";
            this->deleteButton->UseVisualStyleBackColor = true;
            this->deleteButton->Click += gcnew System::EventHandler(this, &ManageStudents::deleteButton_Click);
            // 
            // firstNameTextBox
            // 
            this->firstNameTextBox->Location = System::Drawing::Point(12, 350);
            this->firstNameTextBox->Name = L"firstNameTextBox";
            this->firstNameTextBox->Size = System::Drawing::Size(237, 26);
            this->firstNameTextBox->TabIndex = 4;
            // 
            // lastNameTextBox
            // 
            this->lastNameTextBox->Location = System::Drawing::Point(255, 350);
            this->lastNameTextBox->Name = L"lastNameTextBox";
            this->lastNameTextBox->Size = System::Drawing::Size(237, 26);
            this->lastNameTextBox->TabIndex = 5;
            // 
            // studentIDTextBox
            // 
            this->studentIDTextBox->Location = System::Drawing::Point(498, 350);
            this->studentIDTextBox->Name = L"studentIDTextBox";
            this->studentIDTextBox->Size = System::Drawing::Size(237, 26);
            this->studentIDTextBox->TabIndex = 6;
            // 
            // majorTextBox
            // 
            this->majorTextBox->Location = System::Drawing::Point(12, 400);
            this->majorTextBox->Name = L"majorTextBox";
            this->majorTextBox->Size = System::Drawing::Size(237, 26);
            this->majorTextBox->TabIndex = 7;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 327);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(84, 20);
            this->label1->TabIndex = 8;
            this->label1->Text = L"First Name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(255, 327);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(84, 20);
            this->label2->TabIndex = 9;
            this->label2->Text = L"Last Name";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(498, 327);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(87, 20);
            this->label3->TabIndex = 10;
            this->label3->Text = L"Student ID";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(12, 377);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(48, 20);
            this->label4->TabIndex = 11;
            this->label4->Text = L"Major";
            // 
            // ManageStudents
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 500);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->majorTextBox);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->studentIDTextBox);
            this->Controls->Add(this->lastNameTextBox);
            this->Controls->Add(this->firstNameTextBox);
            this->Controls->Add(this->deleteButton);
            this->Controls->Add(this->updateButton);
            this->Controls->Add(this->addButton);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"ManageStudents";
            this->Text = L"ManageStudents";
            this->Load += gcnew System::EventHandler(this, &ManageStudents::ManageStudents_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::String^ GenerateRandomPassword(int length)
    {
        String^ chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
        Random^ random = gcnew Random();
        String^ password = "";
        for (int i = 0; i < length; i++)
        {
            password += chars[random->Next(chars->Length)];
        }
        return password;
    }

    private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
        Console::WriteLine("Add button clicked");
        String^ firstName = this->firstNameTextBox->Text;
        String^ lastName = this->lastNameTextBox->Text;
        String^ major = this->majorTextBox->Text;
        String^ email = firstName + lastName + "@gmail.com";
        String^ password = GenerateRandomPassword(8);

        Console::WriteLine("First Name: " + firstName);
        Console::WriteLine("Last Name: " + lastName);
        Console::WriteLine("Email: " + email);
        Console::WriteLine("Password: " + password);
        Console::WriteLine("Major: " + major);

        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to insert a new student
        String^ query = "INSERT INTO users (firstName, lastName, email, password, roleID) VALUES (@FirstName, @LastName, @Email, @Password, 3);";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);
        command->Parameters->AddWithValue("@FirstName", firstName);
        command->Parameters->AddWithValue("@LastName", lastName);
        command->Parameters->AddWithValue("@Email", email);
        command->Parameters->AddWithValue("@Password", password);

        try
        {
            Console::WriteLine("Opening connection");
            connection->Open();
            Console::WriteLine("Executing query");
            command->ExecuteNonQuery();

            // Get the last inserted user ID
            int userID = Convert::ToInt32(command->LastInsertedId);

            // Insert into student table
            query = "INSERT INTO student (userID, major) VALUES (@UserID, @Major)";
            command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@UserID", userID);
            command->Parameters->AddWithValue("@Major", major);
            command->ExecuteNonQuery();

            MessageBox::Show("Student added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            LoadStudents();
        }
        catch (Exception^ ex)
        {
            Console::WriteLine("Error: " + ex->Message);
            MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally
        {
            Console::WriteLine("Closing connection");
            connection->Close();
        }
    }






    private: System::Void updateButton_Click(System::Object^ sender, System::EventArgs^ e) {
        Console::WriteLine("Update button clicked");
        if (dataGridView1->SelectedRows->Count > 0)
        {
            int studentID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["studentID"]->Value);
            String^ firstName = this->firstNameTextBox->Text;
            String^ lastName = this->lastNameTextBox->Text;
            String^ major = this->majorTextBox->Text;
            String^ email = firstName + lastName + "@gmail.com";

            Console::WriteLine("Student ID: " + studentID);
            Console::WriteLine("First Name: " + firstName);
            Console::WriteLine("Last Name: " + lastName);
            Console::WriteLine("Email: " + email);
            Console::WriteLine("Major: " + major);

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to update the student
            String^ query = "UPDATE users SET firstName = @FirstName, lastName = @LastName, email = @Email WHERE userID = @StudentID; " +
                "UPDATE student SET major = @Major WHERE userID = @StudentID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@FirstName", firstName);
            command->Parameters->AddWithValue("@LastName", lastName);
            command->Parameters->AddWithValue("@Email", email);
            command->Parameters->AddWithValue("@Major", major);
            command->Parameters->AddWithValue("@StudentID", studentID);

            try
            {
                Console::WriteLine("Opening connection");
                connection->Open();
                Console::WriteLine("Executing query");
                command->ExecuteNonQuery();
                MessageBox::Show("Student updated successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadStudents();
            }
            catch (Exception^ ex)
            {
                Console::WriteLine("Error: " + ex->Message);
                MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally
            {
                Console::WriteLine("Closing connection");
                connection->Close();
            }
        }
        else
        {
            Console::WriteLine("No student selected for update");
            MessageBox::Show("Please select a student to update", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
        Console::WriteLine("Delete button clicked");
        if (dataGridView1->SelectedRows->Count > 0)
        {
            int studentID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["studentID"]->Value);

            Console::WriteLine("Student ID: " + studentID);

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to delete the student
            String^ query = "DELETE FROM student WHERE studentID = @StudentID; " +
                "DELETE FROM users WHERE userID = (SELECT userID FROM student WHERE studentID = @StudentID)";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@StudentID", studentID);

            try
            {
                Console::WriteLine("Opening connection");
                connection->Open();
                Console::WriteLine("Executing query");
                command->ExecuteNonQuery();
                MessageBox::Show("Student deleted successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadStudents();
            }
            catch (Exception^ ex)
            {
                Console::WriteLine("Error: " + ex->Message);
                MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally
            {
                Console::WriteLine("Closing connection");
                connection->Close();
            }
        }
        else
        {
            Console::WriteLine("No student selected for deletion");
            MessageBox::Show("Please select a student to delete", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }


        private: void LoadStudents()
        {
            Console::WriteLine("Loading students");
            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to retrieve the students
            String^ query = "SELECT s.studentID, u.firstName, u.lastName, s.major FROM student s JOIN users u ON s.userID = u.userID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);

            try
            {
                Console::WriteLine("Opening connection");
                connection->Open();

                // Execute the query and load the data into a DataTable
                MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(command);
                DataTable^ dataTable = gcnew DataTable();
                adapter->Fill(dataTable);

                // Bind the DataTable to the DataGridView
                dataGridView1->DataSource = dataTable;
                Console::WriteLine("Students loaded successfully");
            }
            catch (Exception^ ex)
            {
                // Show an error message
                Console::WriteLine("Error: " + ex->Message);
                MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            finally
            {
                // Close the connection
                Console::WriteLine("Closing connection");
                connection->Close();
            }
        }

    private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0)
        {
            DataGridViewRow^ row = dataGridView1->Rows[e->RowIndex];
            studentIDTextBox->Text = row->Cells["studentID"]->Value->ToString();
            firstNameTextBox->Text = row->Cells["firstName"]->Value->ToString();
            lastNameTextBox->Text = row->Cells["lastName"]->Value->ToString();
            majorTextBox->Text = row->Cells["major"]->Value->ToString();
            Console::WriteLine("Selected student ID: " + studentIDTextBox->Text);
        }
    }

    private: System::Void ManageStudents_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadStudents();
    }
};
}
