#pragma once

namespace FinalProjectVPN {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class EnrollmentForm : public System::Windows::Forms::Form
    {
    public:
        // Constructor, assuming the UserID is passed to the form
        EnrollmentForm(int userID)
        {
            InitializeComponent();

            // Check if the userID corresponds to a valid student
            int studentID = GetStudentIDByUserID(userID);

            if (studentID != -1)
            {
                this->studentID = studentID;
            }
            else
            {
                MessageBox::Show("Invalid User ID: " + userID, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                this->Close();
            }
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~EnrollmentForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        int studentID;

        System::Windows::Forms::Button^ Submit_button;
        System::Windows::Forms::ComboBox^ CoursesComboBox;
        System::Windows::Forms::Label^ label3;

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
            this->Submit_button = (gcnew System::Windows::Forms::Button());
            this->CoursesComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // Submit_button
            // 
            this->Submit_button->Location = System::Drawing::Point(335, 337);
            this->Submit_button->Name = L"Submit_button";
            this->Submit_button->Size = System::Drawing::Size(100, 37);
            this->Submit_button->TabIndex = 4;
            this->Submit_button->Text = L"Submit ";
            this->Submit_button->UseVisualStyleBackColor = true;
            this->Submit_button->Click += gcnew System::EventHandler(this, &EnrollmentForm::Submit_button_Click);
            // 
            // CoursesComboBox
            // 
            this->CoursesComboBox->FormattingEnabled = true;
            // Example course list, you can populate it from a database
            this->CoursesComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
                L"Artificial Intelligence", L"Mathematics",
                    L"Computer Science"
            });
            this->CoursesComboBox->Location = System::Drawing::Point(413, 207);
            this->CoursesComboBox->Name = L"CoursesComboBox";
            this->CoursesComboBox->Size = System::Drawing::Size(121, 28);
            this->CoursesComboBox->TabIndex = 5;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(264, 207);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(60, 20);
            this->label3->TabIndex = 6;
            this->label3->Text = L"Course";
            // 
            // EnrollmentForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1361, 608);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->CoursesComboBox);
            this->Controls->Add(this->Submit_button);
            this->Name = L"EnrollmentForm";
            this->Text = L"EnrollmentForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void Submit_button_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ course = this->CoursesComboBox->SelectedItem->ToString();

        // Database connection string
        String^ connectionString = "Server = localhost; Database = university; Uid = root; Pwd = ''; ";

        // SQL query to insert the enrollment details
        String^ query = "INSERT INTO Enrollments (studentID, courseID, enrollmentDate) VALUES (@StudentID, @CourseID, @EnrollmentDate)";

        // Get courseID from the selected course name
        int courseID = GetCourseIDByName(course);
        String^ enrollmentDate = DateTime::Now.ToString("yyyy-MM-dd");

        // Create a connection to the database
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        MySqlCommand^ command = gcnew MySqlCommand(query, connection);

        // Add parameters to the SQL query
        command->Parameters->AddWithValue("@StudentID", studentID);
        command->Parameters->AddWithValue("@CourseID", courseID);
        command->Parameters->AddWithValue("@EnrollmentDate", enrollmentDate);

        try
        {
            // Open the connection
            connection->Open();

            // Execute the query
            command->ExecuteNonQuery();

            // Show a success message
            MessageBox::Show("Student Enrolled Successfully", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
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

        this->Close();
    }

           // Function to get the studentID by querying the database using userID
           int GetStudentIDByUserID(int userID)
           {
               int studentID = -1; // Default value to represent "not found"

               // Database connection string
               String^ connectionString = "Server = localhost; Database = university; Uid = root; Pwd = ''; ";

               // SQL query to get the studentID by matching userID
               String^ query = "SELECT studentID FROM student WHERE userID = @UserID";

               // Create a connection to the database
               MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
               MySqlCommand^ command = gcnew MySqlCommand(query, connection);
               command->Parameters->AddWithValue("@UserID", userID);

               try
               {
                   // Open the connection
                   connection->Open();

                   // Execute the query and retrieve the studentID
                   Object^ result = command->ExecuteScalar();
                   if (result != nullptr)
                   {
                       studentID = Convert::ToInt32(result); // Convert the result to an integer
                   }
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

               return studentID; // Return the studentID (or -1 if not found)
           }

           // Function to get the courseID by courseName
           int GetCourseIDByName(String^ courseName)
           {
               int courseID = -1; // Default value to represent "not found"

               // Database connection string
               String^ connectionString = "Server = localhost; Database = university; Uid = root; Pwd = ''; ";

               // SQL query to get the courseID by matching courseName
               String^ query = "SELECT courseID FROM course WHERE courseName = @CourseName";

               // Create a connection to the database
               MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
               MySqlCommand^ command = gcnew MySqlCommand(query, connection);
               command->Parameters->AddWithValue("@CourseName", courseName);

               try
               {
                   // Open the connection
                   connection->Open();

                   // Execute the query and retrieve the courseID
                   Object^ result = command->ExecuteScalar();
                   if (result != nullptr)
                   {
                       courseID = Convert::ToInt32(result); // Convert the result to an integer
                   }
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

               return courseID; // Return the courseID (or -1 if not found)
           }
    };
}
