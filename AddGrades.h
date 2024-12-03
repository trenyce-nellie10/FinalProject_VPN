#pragma once

namespace FinalProjectVPN {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Data::SqlClient;
    using namespace MySql::Data::MySqlClient;
    using namespace System::Collections::Generic;

    public ref class AddGrades : public System::Windows::Forms::Form
    {
    public:
        AddGrades(int userId)
        {
            // Ensure components are initialized first
            InitializeComponent();

            // Initialize lists
            allowedStudents = gcnew List<String^>();
            allowedCourses = gcnew List<String^>();
            courseIDList = gcnew List<String^>();

            currentUserId = userId;

            // First, validate and get faculty department
            String^ facultyDepartment = GetFacultyDepartment();

            // Then populate courses based on department
            if (!String::IsNullOrEmpty(facultyDepartment))
            {
                PopulateAllowedCourses(facultyDepartment);
            }
        }

    protected:
        ~AddGrades()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::ComboBox^ studentID;
        System::Windows::Forms::ComboBox^ courseID;
        System::Windows::Forms::TextBox^ grade;
        System::Windows::Forms::Button^ submit;
        List<String^>^ allowedStudents;
        List<String^>^ allowedCourses;
        List<String^>^ courseIDList; // Separate list to store course IDs
        int currentUserId;
        System::ComponentModel::Container^ components;

    private:
        // Get faculty department
        String^ GetFacultyDepartment()
        {
            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            String^ query = "SELECT department FROM faculty WHERE userID = @userId";

            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@userId", currentUserId);

            try
            {
                connection->Open();
                Object^ result = command->ExecuteScalar();
                return result != nullptr ? result->ToString() : nullptr;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error retrieving department: " + ex->Message);
                return nullptr;
            }
            finally
            {
                connection->Close();
            }
        }

        // Populate allowed courses based on faculty department
        void PopulateAllowedCourses(String^ department)
        {
            if (courseID == nullptr) return;

            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            String^ query = "SELECT courseID, courseName FROM course WHERE courseName = @department";

            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@department", department);

            try
            {
                connection->Open();
                MySqlDataReader^ reader = command->ExecuteReader();
                courseID->Items->Clear();
                allowedCourses->Clear();
                courseIDList->Clear();

                while (reader->Read())
                {
                    String^ courseIdValue = reader["courseID"]->ToString();
                    String^ courseName = reader["courseName"]->ToString();
                    courseID->Items->Add(courseName);
                    allowedCourses->Add(courseName);
                    courseIDList->Add(courseIdValue);
                }

                // Select first course by default if available
                if (courseID->Items->Count > 0)
                {
                    courseID->SelectedIndex = 0;
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading courses: " + ex->Message);
            }
            finally
            {
                connection->Close();
            }
        }

        // Populate students based on selected course
        void PopulateAllowedStudents()
        {
            if (courseID == nullptr || studentID == nullptr) return;

            int selectedIndex = courseID->SelectedIndex;
            if (selectedIndex < 0 || selectedIndex >= courseIDList->Count) return;

            String^ selectedCourseId = courseIDList[selectedIndex];

            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            String^ query = "SELECT DISTINCT s.studentID, u.firstName, u.lastName " +
                "FROM enrollments e " +
                "JOIN student s ON e.studentID = s.studentID " +
                "JOIN users u ON s.userID = u.userID " +
                "WHERE e.courseID = @courseId";

            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@courseId", selectedCourseId);

            try
            {
                connection->Open();
                studentID->Items->Clear();
                allowedStudents->Clear();

                MySqlDataReader^ reader = command->ExecuteReader();
                while (reader->Read())
                {
                    String^ studentDisplay = reader->GetString(1) + " " + reader->GetString(2);
                    studentID->Items->Add(studentDisplay);
                    allowedStudents->Add(reader->GetString(0)); // Store studentID
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading students: " + ex->Message);
            }
            finally
            {
                connection->Close();
            }
        }

        // Submit button click handler
        void submit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (studentID == nullptr || courseID == nullptr || grade == nullptr) return;

            if (studentID->SelectedIndex == -1 || courseID->SelectedIndex == -1 ||
                String::IsNullOrWhiteSpace(grade->Text))
            {
                MessageBox::Show("Please fill all fields.");
                return;
            }

            String^ studentId = allowedStudents[studentID->SelectedIndex];
            String^ courseId = courseIDList[courseID->SelectedIndex];
            String^ gradeValue = grade->Text;

            String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";
            MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
            String^ query = "INSERT INTO grades (studentID, courseID, grade) " +
                "VALUES (@studentId, @courseId, @grade) " +
                "ON DUPLICATE KEY UPDATE grade = @grade";

            MySqlCommand^ command = gcnew MySqlCommand(query, connection);
            command->Parameters->AddWithValue("@studentId", studentId);
            command->Parameters->AddWithValue("@courseId", courseId);
            command->Parameters->AddWithValue("@grade", gradeValue);

            try
            {
                connection->Open();
                command->ExecuteNonQuery();
                MessageBox::Show("Grade added successfully!");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error adding grade: " + ex->Message);
            }
            finally
            {
                connection->Close();
            }
        }

        void InitializeComponent(void)
        {
            // Initialize all UI components
            this->studentID = gcnew System::Windows::Forms::ComboBox();
            this->courseID = gcnew System::Windows::Forms::ComboBox();
            this->grade = gcnew System::Windows::Forms::TextBox();
            this->submit = gcnew System::Windows::Forms::Button();

            // Set properties for the components
            this->studentID->Location = System::Drawing::Point(50, 50);
            this->studentID->Size = System::Drawing::Size(200, 30);

            this->courseID->Location = System::Drawing::Point(50, 100);
            this->courseID->Size = System::Drawing::Size(200, 30);

            this->grade->Location = System::Drawing::Point(50, 150);
            this->grade->Size = System::Drawing::Size(200, 30);

            this->submit->Location = System::Drawing::Point(50, 200);
            this->submit->Size = System::Drawing::Size(100, 30);
            this->submit->Text = "Submit";

            // Add components to the form
            this->Controls->Add(this->studentID);
            this->Controls->Add(this->courseID);
            this->Controls->Add(this->grade);
            this->Controls->Add(this->submit);

            // Set up event handlers
            this->courseID->SelectedIndexChanged +=
                gcnew System::EventHandler(this, &AddGrades::courseID_SelectedIndexChanged);
            this->submit->Click +=
                gcnew System::EventHandler(this, &AddGrades::submit_Click);

            // Set form properties
            this->Text = "Add Grades";
            this->Size = System::Drawing::Size(300, 300);
        }

        // Event handler for course selection
        void courseID_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            PopulateAllowedStudents();
        }
    };
}

