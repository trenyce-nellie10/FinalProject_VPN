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
	/// Summary for ViewSchedule
	/// </summary>
	public ref class ViewSchedule : public System::Windows::Forms::Form
	{
	public:
		ViewSchedule(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ViewSchedule()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(138, 171);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(451, 231);
			this->dataGridView1->TabIndex = 0;
			// 
			// ViewSchedule
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(752, 503);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"ViewSchedule";
			this->Text = L"ViewSchedule";
			this->Load += gcnew System::EventHandler(this, &ViewSchedule::ViewSchedule_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ViewSchedule_Load(System::Object^ sender, System::EventArgs^ e) {
		String^ connectionString = "Data Source=your_server_name;Initial Catalog=your_database_name;Integrated Security=True";

		// SQL query to retrieve the schedule data
		String^ query = "SELECT * FROM Schedule WHERE StudentID = @StudentID";

		// Create a connection to the database
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		MySqlCommand^ command = gcnew MySqlCommand(query, connection);

		// Replace with the actual student ID
		int studentID = 1; // Example student ID
		command->Parameters->AddWithValue("@StudentID", studentID);

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
