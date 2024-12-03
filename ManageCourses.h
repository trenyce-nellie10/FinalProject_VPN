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
    /// Summary for ManageCourses
    /// </summary>
    public ref class ManageCourses : public System::Windows::Forms::Form
    {
    public:
        ManageCourses(void)
        {
            InitializeComponent();
            LoadCourses();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ManageCourses()
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
    private: System::Windows::Forms::TextBox^ courseNameTextBox;
    private: System::Windows::Forms::Label^ label1;

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
            this->courseNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
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
            this->addButton->Size = System::Drawing::Size(75, 31);
            this->addButton->TabIndex = 1;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &ManageCourses::addButton_Click);
            // 
            // updateButton
            // 
            this->updateButton->Location = System::Drawing::Point(93, 400);
            this->updateButton->Name = L"updateButton";
            this->updateButton->Size = System::Drawing::Size(75, 31);
            this->updateButton->TabIndex = 2;
            this->updateButton->Text = L"Update";
            this->updateButton->UseVisualStyleBackColor = true;
            this->updateButton->Click += gcnew System::EventHandler(this, &ManageCourses::updateButton_Click);
            // 
            // deleteButton
            // 
            this->deleteButton->Location = System::Drawing::Point(174, 400);
            this->deleteButton->Name = L"deleteButton";
            this->deleteButton->Size = System::Drawing::Size(89, 31);
            this->deleteButton->TabIndex = 3;
            this->deleteButton->Text = L"Delete";
            this->deleteButton->UseVisualStyleBackColor = true;
            this->deleteButton->Click += gcnew System::EventHandler(this, &ManageCourses::deleteButton_Click);
            // 
            // courseNameTextBox
            // 
            this->courseNameTextBox->Location = System::Drawing::Point(12, 350);
            this->courseNameTextBox->Name = L"courseNameTextBox";
            this->courseNameTextBox->Size = System::Drawing::Size(237, 26);
            this->courseNameTextBox->TabIndex = 4;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 327);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(106, 20);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Course Name";
            // 
            // ManageCourses
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 471);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->courseNameTextBox);
            this->Controls->Add(this->deleteButton);
            this->Controls->Add(this->updateButton);
            this->Controls->Add(this->addButton);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"ManageCourses";
            this->Text = L"ManageCourses";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ courseName = this->courseNameTextBox->Text;

        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to insert a new course
        String^ query = "INSERT INTO course (courseName) VALUES (@CourseName)";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);
        command->Parameters->AddWithValue("@CourseName", courseName);

        try
        {
            connection->Open();
            command->ExecuteNonQuery();
            MessageBox::Show("Course added successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            LoadCourses();
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
            int courseID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["courseID"]->Value);
            String^ courseName = this->courseNameTextBox->Text;

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to update the course
            String^ query = "UPDATE course SET courseName = @CourseName WHERE courseID = @CourseID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@CourseName", courseName);
            command->Parameters->AddWithValue("@CourseID", courseID);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Course updated successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadCourses();
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
            MessageBox::Show("Please select a course to update", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
        if (dataGridView1->SelectedRows->Count > 0)
        {
            int courseID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["courseID"]->Value);

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to delete the course
            String^ query = "DELETE FROM course WHERE courseID = @CourseID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@CourseID", courseID);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Course deleted successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LoadCourses();
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
            MessageBox::Show("Please select a course to delete", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    }

    private: void LoadCourses()
    {
        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to retrieve the courses
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
    };
}

