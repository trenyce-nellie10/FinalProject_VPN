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
    private: System::Windows::Forms::TextBox^ courseIDTextBox;
    private: System::Windows::Forms::TextBox^ courseNameTextBox;
    private: System::Windows::Forms::TextBox^ courseDescriptionTextBox;
    private: System::Windows::Forms::TextBox^ creditsTextBox;
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
            this->courseIDTextBox = (gcnew System::Windows::Forms::TextBox());
            this->courseNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->courseDescriptionTextBox = (gcnew System::Windows::Forms::TextBox());
            this->creditsTextBox = (gcnew System::Windows::Forms::TextBox());
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
            // 
            // addButton
            // 
            this->addButton->Location = System::Drawing::Point(12, 500);
            this->addButton->Name = L"addButton";
            this->addButton->Size = System::Drawing::Size(75, 31);
            this->addButton->TabIndex = 1;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &ManageCourses::addButton_Click);
            // 
            // updateButton
            // 
            this->updateButton->Location = System::Drawing::Point(93, 500);
            this->updateButton->Name = L"updateButton";
            this->updateButton->Size = System::Drawing::Size(75, 31);
            this->updateButton->TabIndex = 2;
            this->updateButton->Text = L"Update";
            this->updateButton->UseVisualStyleBackColor = true;
            this->updateButton->Click += gcnew System::EventHandler(this, &ManageCourses::updateButton_Click);
            // 
            // deleteButton
            // 
            this->deleteButton->Location = System::Drawing::Point(174, 500);
            this->deleteButton->Name = L"deleteButton";
            this->deleteButton->Size = System::Drawing::Size(89, 31);
            this->deleteButton->TabIndex = 3;
            this->deleteButton->Text = L"Delete";
            this->deleteButton->UseVisualStyleBackColor = true;
            this->deleteButton->Click += gcnew System::EventHandler(this, &ManageCourses::deleteButton_Click);
            // 
            // courseIDTextBox
            // 
            this->courseIDTextBox->Location = System::Drawing::Point(12, 350);
            this->courseIDTextBox->Name = L"courseIDTextBox";
            this->courseIDTextBox->Size = System::Drawing::Size(100, 26);
            this->courseIDTextBox->TabIndex = 4;
            // 
            // courseNameTextBox
            // 
            this->courseNameTextBox->Location = System::Drawing::Point(118, 350);
            this->courseNameTextBox->Name = L"courseNameTextBox";
            this->courseNameTextBox->Size = System::Drawing::Size(237, 26);
            this->courseNameTextBox->TabIndex = 5;
            // 
            // courseDescriptionTextBox
            // 
            this->courseDescriptionTextBox->Location = System::Drawing::Point(361, 350);
            this->courseDescriptionTextBox->Name = L"courseDescriptionTextBox";
            this->courseDescriptionTextBox->Size = System::Drawing::Size(237, 26);
            this->courseDescriptionTextBox->TabIndex = 6;
            // 
            // creditsTextBox
            // 
            this->creditsTextBox->Location = System::Drawing::Point(604, 350);
            this->creditsTextBox->Name = L"creditsTextBox";
            this->creditsTextBox->Size = System::Drawing::Size(100, 26);
            this->creditsTextBox->TabIndex = 7;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 327);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(79, 20);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Course ID";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(118, 327);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(106, 20);
            this->label2->TabIndex = 9;
            this->label2->Text = L"Course Name";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(361, 327);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(137, 20);
            this->label3->TabIndex = 10;
            this->label3->Text = L"Course Description";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(604, 327);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(63, 20);
            this->label4->TabIndex = 11;
            this->label4->Text = L"Credits";
            // 
            // ManageCourses
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 550);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->creditsTextBox);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->courseDescriptionTextBox);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->courseNameTextBox);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->courseIDTextBox);
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
        int courseID = Convert::ToInt32(this->courseIDTextBox->Text);
        String^ courseName = this->courseNameTextBox->Text;
        String^ courseDescription = this->courseDescriptionTextBox->Text;
        int credits = Convert::ToInt32(this->creditsTextBox->Text);

        // Database connection string
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

        // SQL query to insert a new course
        String^ query = "INSERT INTO course (courseID, courseName, courseDescription, credits) VALUES (@CourseID, @CourseName, @CourseDescription, @Credits)";

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);
        command->Parameters->AddWithValue("@CourseID", courseID);
        command->Parameters->AddWithValue("@CourseName", courseName);
        command->Parameters->AddWithValue("@CourseDescription", courseDescription);
        command->Parameters->AddWithValue("@Credits", credits);

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
            String^ courseDescription = this->courseDescriptionTextBox->Text;
            int credits = Convert::ToInt32(this->creditsTextBox->Text);

            // Database connection string
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

            // SQL query to update the course
            String^ query = "UPDATE course SET courseName = @CourseName, courseDescription = @CourseDescription, credits = @Credits WHERE courseID = @CourseID";

            // Create a connection to the database
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@CourseID", courseID);
            command->Parameters->AddWithValue("@CourseName", courseName);
            command->Parameters->AddWithValue("@CourseDescription", courseDescription);
            command->Parameters->AddWithValue("@Credits", credits);

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

