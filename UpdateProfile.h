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
    /// Summary for UpdateProfile
    /// </summary>
    public ref class UpdateProfile : public System::Windows::Forms::Form
    {
    private:
        int userID; // Store the userID for database operations

    public:
        UpdateProfile(int userID)
        {
            InitializeComponent();
            this->userID = userID; // Initialize userID
            LoadProfileData();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~UpdateProfile()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    protected:
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ firstName;

    private: System::Windows::Forms::TextBox^ lastName;

    private: System::Windows::Forms::TextBox^ email;

    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ password;

    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::TextBox^ department;

    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::TextBox^ facultyID;

    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Button^ update;


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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->firstName = (gcnew System::Windows::Forms::TextBox());
            this->lastName = (gcnew System::Windows::Forms::TextBox());
            this->email = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->password = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->department = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->facultyID = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->update = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(216, 61);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(84, 20);
            this->label1->TabIndex = 0;
            this->label1->Text = L"First name";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(219, 119);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(74, 20);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Surname";
            // 
            // firstName
            // 
            this->firstName->Location = System::Drawing::Point(309, 55);
            this->firstName->Name = L"firstName";
            this->firstName->Size = System::Drawing::Size(213, 26);
            this->firstName->TabIndex = 2;
            // 
            // lastName
            // 
            this->lastName->Location = System::Drawing::Point(309, 116);
            this->lastName->Name = L"lastName";
            this->lastName->Size = System::Drawing::Size(213, 26);
            this->lastName->TabIndex = 3;
            // 
            // email
            // 
            this->email->Location = System::Drawing::Point(309, 178);
            this->email->Name = L"email";
            this->email->Size = System::Drawing::Size(213, 26);
            this->email->TabIndex = 5;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(244, 184);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(46, 20);
            this->label3->TabIndex = 4;
            this->label3->Text = L"email";
            // 
            // password
            // 
            this->password->Location = System::Drawing::Point(309, 242);
            this->password->Name = L"password";
            this->password->Size = System::Drawing::Size(213, 26);
            this->password->TabIndex = 7;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(216, 245);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(77, 20);
            this->label4->TabIndex = 6;
            this->label4->Text = L"password";
            // 
            // department
            // 
            this->department->Location = System::Drawing::Point(309, 305);
            this->department->Name = L"department";
            this->department->Size = System::Drawing::Size(213, 26);
            this->department->TabIndex = 9;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(216, 308);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(91, 20);
            this->label5->TabIndex = 8;
            this->label5->Text = L"department";
            // 
            // facultyID
            // 
            this->facultyID->Location = System::Drawing::Point(309, 370);
            this->facultyID->Name = L"facultyID";
            this->facultyID->Size = System::Drawing::Size(213, 26);
            this->facultyID->TabIndex = 11;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Location = System::Drawing::Point(216, 373);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(72, 20);
            this->label6->TabIndex = 10;
            this->label6->Text = L"facultyID";
            // 
            // pictureBox1
            // 
            this->pictureBox1->Location = System::Drawing::Point(32, 55);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(165, 210);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 12;
            this->pictureBox1->TabStop = false;
            // 
            // update
            // 
            this->update->Location = System::Drawing::Point(351, 444);
            this->update->Name = L"update";
            this->update->Size = System::Drawing::Size(106, 28);
            this->update->TabIndex = 13;
            this->update->Text = L"Update";
            this->update->UseVisualStyleBackColor = true;
            this->update->Click += gcnew System::EventHandler(this, &UpdateProfile::update_Click);
            // 
            // UpdateProfile
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(765, 517);
            this->Controls->Add(this->update);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->facultyID);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->department);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->password);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->email);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->lastName);
            this->Controls->Add(this->firstName);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"UpdateProfile";
            this->Text = L"UpdateProfile";
            this->Load += gcnew System::EventHandler(this, &UpdateProfile::UpdateProfile_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void UpdateProfile_Load(System::Object^ sender, System::EventArgs^ e) {
        LoadProfileData();
    }

    private: System::Void update_Click(System::Object^ sender, System::EventArgs^ e) {
        UpdateProfileData();
    }

    private: void LoadProfileData() {
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        String^ query = "SELECT u.firstName, u.lastName, u.email, u.password, f.department, f.facultyID " +
            "FROM users u " +
            "JOIN faculty f ON u.userID = f.userID " +
            "WHERE u.userID = @userID";

        MySqlCommand^ command = gcnew MySqlCommand(query, connection);
        command->Parameters->AddWithValue("@userID", userID);

        try
        {
            connection->Open();
            MySqlDataReader^ reader = command->ExecuteReader();
            if (reader->Read())
            {
                firstName->Text = reader["firstName"]->ToString();
                lastName->Text = reader["lastName"]->ToString();
                email->Text = reader["email"]->ToString();
                password->Text = reader["password"]->ToString();
                department->Text = reader["department"]->ToString();
                facultyID->Text = reader["facultyID"]->ToString();
            }
            else
            {
                MessageBox::Show("No data found for the given user ID.");
            }
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error loading profile data: " + ex->Message);
        }
        finally
        {
            connection->Close();
        }
    }

    private: void UpdateProfileData() {
        String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";
        MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
        String^ query = "UPDATE users u " +
            "JOIN faculty f ON u.userID = f.userID " +
            "SET u.firstName = @firstName, u.lastName = @lastName, u.email = @Email, u.password = @Password, " +
            "f.department = @Department, f.facultyID = @FacultyID " +
            "WHERE u.userID = @userID";

        MySqlCommand^ command = gcnew MySqlCommand(query, connection);
        command->Parameters->AddWithValue("@firstName", firstName->Text);
        command->Parameters->AddWithValue("@lastName", lastName->Text);
        command->Parameters->AddWithValue("@Email", email->Text);
        command->Parameters->AddWithValue("@Password", password->Text);
        command->Parameters->AddWithValue("@Department", department->Text);
        command->Parameters->AddWithValue("@FacultyID", facultyID->Text);
        command->Parameters->AddWithValue("@userID", userID);

        try
        {
            connection->Open();
            command->ExecuteNonQuery();
            MessageBox::Show("Profile updated successfully!");
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error updating profile: " + ex->Message);
        }
        finally
        {
            connection->Close();
        }
    }
    };
}

