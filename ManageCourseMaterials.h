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
	/// Summary for ManageCourseMaterials
	/// </summary>
	public ref class ManageCourseMaterials : public System::Windows::Forms::Form
	{
	public:
		ManageCourseMaterials(void)
		{
			InitializeComponent();
			LoadCourses();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ManageCourseMaterials()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		// Add controls for managing course materials
		System::Windows::Forms::DataGridView^ dataGridView;
		System::Windows::Forms::Button^ addButton;
		System::Windows::Forms::Button^ updateButton;
		System::Windows::Forms::Button^ deleteButton;
		System::Windows::Forms::TextBox^ materialTypeTextBox;
		System::Windows::Forms::TextBox^ materialTitleTextBox;
		System::Windows::Forms::TextBox^ materialPathTextBox;
		System::Windows::Forms::Label^ materialTypeLabel;
		System::Windows::Forms::Label^ materialTitleLabel;
		System::Windows::Forms::Label^ materialPathLabel;
		System::Windows::Forms::ComboBox^ courseComboBox;
		System::Windows::Forms::Label^ courseLabel;

		MySqlConnection^ sqlConn;
		MySqlCommand^ sqlCmd;
		MySqlDataAdapter^ sqlDta;
		DataTable^ sqlDt;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->updateButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->materialTypeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->materialTitleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->materialPathTextBox = (gcnew System::Windows::Forms::TextBox());
			this->materialTypeLabel = (gcnew System::Windows::Forms::Label());
			this->materialTitleLabel = (gcnew System::Windows::Forms::Label());
			this->materialPathLabel = (gcnew System::Windows::Forms::Label());
			this->courseComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->courseLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Location = System::Drawing::Point(12, -3);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersWidth = 62;
			this->dataGridView->RowTemplate->Height = 28;
			this->dataGridView->Size = System::Drawing::Size(776, 300);
			this->dataGridView->TabIndex = 0;
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(12, 505);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(75, 33);
			this->addButton->TabIndex = 1;
			this->addButton->Text = L"Add";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &ManageCourseMaterials::addButton_Click);
			// 
			// updateButton
			// 
			this->updateButton->Location = System::Drawing::Point(93, 505);
			this->updateButton->Name = L"updateButton";
			this->updateButton->Size = System::Drawing::Size(75, 33);
			this->updateButton->TabIndex = 2;
			this->updateButton->Text = L"Update";
			this->updateButton->UseVisualStyleBackColor = true;
			this->updateButton->Click += gcnew System::EventHandler(this, &ManageCourseMaterials::updateButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(174, 505);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(82, 33);
			this->deleteButton->TabIndex = 3;
			this->deleteButton->Text = L"Delete";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &ManageCourseMaterials::deleteButton_Click);
			// 
			// materialTypeTextBox
			// 
			this->materialTypeTextBox->Location = System::Drawing::Point(12, 366);
			this->materialTypeTextBox->Name = L"materialTypeTextBox";
			this->materialTypeTextBox->Size = System::Drawing::Size(776, 26);
			this->materialTypeTextBox->TabIndex = 4;
			// 
			// materialTitleTextBox
			// 
			this->materialTitleTextBox->Location = System::Drawing::Point(12, 416);
			this->materialTitleTextBox->Name = L"materialTitleTextBox";
			this->materialTitleTextBox->Size = System::Drawing::Size(776, 26);
			this->materialTitleTextBox->TabIndex = 5;
			// 
			// materialPathTextBox
			// 
			this->materialPathTextBox->Location = System::Drawing::Point(12, 466);
			this->materialPathTextBox->Name = L"materialPathTextBox";
			this->materialPathTextBox->Size = System::Drawing::Size(776, 26);
			this->materialPathTextBox->TabIndex = 6;
			// 
			// materialTypeLabel
			// 
			this->materialTypeLabel->AutoSize = true;
			this->materialTypeLabel->Location = System::Drawing::Point(12, 343);
			this->materialTypeLabel->Name = L"materialTypeLabel";
			this->materialTypeLabel->Size = System::Drawing::Size(107, 20);
			this->materialTypeLabel->TabIndex = 7;
			this->materialTypeLabel->Text = L"Material Type:";
			// 
			// materialTitleLabel
			// 
			this->materialTitleLabel->AutoSize = true;
			this->materialTitleLabel->Location = System::Drawing::Point(12, 393);
			this->materialTitleLabel->Name = L"materialTitleLabel";
			this->materialTitleLabel->Size = System::Drawing::Size(102, 20);
			this->materialTitleLabel->TabIndex = 8;
			this->materialTitleLabel->Text = L"Material Title:";
			// 
			// materialPathLabel
			// 
			this->materialPathLabel->AutoSize = true;
			this->materialPathLabel->Location = System::Drawing::Point(12, 443);
			this->materialPathLabel->Name = L"materialPathLabel";
			this->materialPathLabel->Size = System::Drawing::Size(106, 20);
			this->materialPathLabel->TabIndex = 9;
			this->materialPathLabel->Text = L"Material Path:";
			// 
			// courseComboBox
			// 
			this->courseComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->courseComboBox->FormattingEnabled = true;
			this->courseComboBox->Location = System::Drawing::Point(12, 316);
			this->courseComboBox->Name = L"courseComboBox";
			this->courseComboBox->Size = System::Drawing::Size(776, 28);
			this->courseComboBox->TabIndex = 10;
			// 
			// courseLabel
			// 
			this->courseLabel->AutoSize = true;
			this->courseLabel->Location = System::Drawing::Point(12, 293);
			this->courseLabel->Name = L"courseLabel";
			this->courseLabel->Size = System::Drawing::Size(64, 20);
			this->courseLabel->TabIndex = 11;
			this->courseLabel->Text = L"Course:";
			this->courseLabel->Click += gcnew System::EventHandler(this, &ManageCourseMaterials::courseLabel_Click);
			// 
			// ManageCourseMaterials
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 550);
			this->Controls->Add(this->courseLabel);
			this->Controls->Add(this->courseComboBox);
			this->Controls->Add(this->materialPathLabel);
			this->Controls->Add(this->materialTitleLabel);
			this->Controls->Add(this->materialTypeLabel);
			this->Controls->Add(this->materialPathTextBox);
			this->Controls->Add(this->materialTitleTextBox);
			this->Controls->Add(this->materialTypeTextBox);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->updateButton);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->dataGridView);
			this->Name = L"ManageCourseMaterials";
			this->Text = L"Manage Course Materials";
			this->Load += gcnew System::EventHandler(this, &ManageCourseMaterials::ManageCourseMaterials_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ManageCourseMaterials_Load(System::Object^ sender, System::EventArgs^ e) {
		// Load course materials from the database
		LoadCourseMaterials();
	}

	private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Add new course material to the database
		AddCourseMaterial();
	}

	private: System::Void updateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Update selected course material in the database
		UpdateCourseMaterial();
	}

	private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Delete selected course material from the database
		DeleteCourseMaterial();
	}

	private: void LoadCourses() {
		String^ connString = "Server=localhost;Database=university;Uid=root;Pwd='';";
		sqlConn = gcnew MySqlConnection(connString);
		sqlCmd = gcnew MySqlCommand("SELECT courseID, courseName FROM course", sqlConn);
		sqlDta = gcnew MySqlDataAdapter(sqlCmd);
		sqlDt = gcnew DataTable();
		sqlDta->Fill(sqlDt);
		courseComboBox->DataSource = sqlDt;
		courseComboBox->DisplayMember = "courseName";
		courseComboBox->ValueMember = "courseID";
	}

	private: void LoadCourseMaterials() {
		String^ connString = "Server=localhost;Database=university;Uid=root;Pwd='';";
		sqlConn = gcnew MySqlConnection(connString);
		sqlCmd = gcnew MySqlCommand("SELECT * FROM CourseMaterials", sqlConn);
		sqlDta = gcnew MySqlDataAdapter(sqlCmd);
		sqlDt = gcnew DataTable();
		sqlDta->Fill(sqlDt);
		dataGridView->DataSource = sqlDt;
	}

	private: void AddCourseMaterial() {
		String^ connString = "Server=localhost;Database=university;Uid=root;Pwd='';";
		sqlConn = gcnew MySqlConnection(connString);
		sqlCmd = gcnew MySqlCommand("INSERT INTO CourseMaterials (courseID, materialType, materialTitle, materialPath) VALUES (@courseID, @materialType, @materialTitle, @materialPath)", sqlConn);
		sqlCmd->Parameters->AddWithValue("@courseID", courseComboBox->SelectedValue);
		sqlCmd->Parameters->AddWithValue("@materialType", materialTypeTextBox->Text);
		sqlCmd->Parameters->AddWithValue("@materialTitle", materialTitleTextBox->Text);
		sqlCmd->Parameters->AddWithValue("@materialPath", materialPathTextBox->Text);
		sqlConn->Open();
		sqlCmd->ExecuteNonQuery();
		sqlConn->Close();
		LoadCourseMaterials();
	}

	private: void UpdateCourseMaterial() {
		if (dataGridView->SelectedRows->Count > 0) {
			int materialID = Convert::ToInt32(dataGridView->SelectedRows[0]->Cells["materialID"]->Value);
			String^ connString = "Server=localhost;Database=university;Uid=root;Pwd='';";
			sqlConn = gcnew MySqlConnection(connString);
			sqlCmd = gcnew MySqlCommand("UPDATE CourseMaterials SET courseID=@courseID, materialType=@materialType, materialTitle=@materialTitle, materialPath=@materialPath WHERE materialID=@materialID", sqlConn);
			sqlCmd->Parameters->AddWithValue("@courseID", courseComboBox->SelectedValue);
			sqlCmd->Parameters->AddWithValue("@materialType", materialTypeTextBox->Text);
			sqlCmd->Parameters->AddWithValue("@materialTitle", materialTitleTextBox->Text);
			sqlCmd->Parameters->AddWithValue("@materialPath", materialPathTextBox->Text);
			sqlCmd->Parameters->AddWithValue("@materialID", materialID);
			sqlConn->Open();
			sqlCmd->ExecuteNonQuery();
			sqlConn->Close();
			LoadCourseMaterials();
		}
	}

	private: void DeleteCourseMaterial() {
		if (dataGridView->SelectedRows->Count > 0) {
			int materialID = Convert::ToInt32(dataGridView->SelectedRows[0]->Cells["materialID"]->Value);
			String^ connString = "Server=localhost;Database=university;Uid=root;Pwd='';";
			sqlConn = gcnew MySqlConnection(connString);
			sqlCmd = gcnew MySqlCommand("DELETE FROM CourseMaterials WHERE materialID=@materialID", sqlConn);
			sqlCmd->Parameters->AddWithValue("@materialID", materialID);
			sqlConn->Open();
			sqlCmd->ExecuteNonQuery();
			sqlConn->Close();
			LoadCourseMaterials();
		}
	}
	private: System::Void courseLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

