#pragma once

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class ViewTranscript : public System::Windows::Forms::Form
	{
	public:
		ViewTranscript(int userID)
		{
			InitializeComponent();
			this->userID = userID;
		}

	protected:
		~ViewTranscript()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		int userID;
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ textBoxStudentID;
		System::Windows::Forms::Button^ buttonViewTranscript;
		System::Windows::Forms::DataGridView^ dataGridViewTranscript;
		System::Windows::Forms::Button^ buttonDownload;

		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxStudentID = (gcnew System::Windows::Forms::TextBox());
			this->buttonViewTranscript = (gcnew System::Windows::Forms::Button());
			this->dataGridViewTranscript = (gcnew System::Windows::Forms::DataGridView());
			this->buttonDownload = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTranscript))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Student ID:";
			// 
			// textBoxStudentID
			// 
			this->textBoxStudentID->Location = System::Drawing::Point(101, 10);
			this->textBoxStudentID->Name = L"textBoxStudentID";
			this->textBoxStudentID->Size = System::Drawing::Size(200, 26);
			this->textBoxStudentID->TabIndex = 1;
			// 
			// buttonViewTranscript
			// 
			this->buttonViewTranscript->Location = System::Drawing::Point(307, 8);
			this->buttonViewTranscript->Name = L"buttonViewTranscript";
			this->buttonViewTranscript->Size = System::Drawing::Size(75, 30);
			this->buttonViewTranscript->TabIndex = 2;
			this->buttonViewTranscript->Text = L"View";
			this->buttonViewTranscript->UseVisualStyleBackColor = true;
			this->buttonViewTranscript->Click += gcnew System::EventHandler(this, &ViewTranscript::buttonViewTranscript_Click);
			// 
			// dataGridViewTranscript
			// 
			this->dataGridViewTranscript->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTranscript->Location = System::Drawing::Point(17, 50);
			this->dataGridViewTranscript->Name = L"dataGridViewTranscript";
			this->dataGridViewTranscript->RowHeadersWidth = 62;
			this->dataGridViewTranscript->RowTemplate->Height = 28;
			this->dataGridViewTranscript->Size = System::Drawing::Size(600, 300);
			this->dataGridViewTranscript->TabIndex = 3;
			// 
			// buttonDownload
			// 
			this->buttonDownload->Location = System::Drawing::Point(17, 360);
			this->buttonDownload->Name = L"buttonDownload";
			this->buttonDownload->Size = System::Drawing::Size(100, 30);
			this->buttonDownload->TabIndex = 4;
			this->buttonDownload->Text = L"Download";
			this->buttonDownload->UseVisualStyleBackColor = true;
			this->buttonDownload->Click += gcnew System::EventHandler(this, &ViewTranscript::buttonDownload_Click);
			// 
			// ViewTranscript
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 401);
			this->Controls->Add(this->buttonDownload);
			this->Controls->Add(this->dataGridViewTranscript);
			this->Controls->Add(this->buttonViewTranscript);
			this->Controls->Add(this->textBoxStudentID);
			this->Controls->Add(this->label1);
			this->Name = L"ViewTranscript";
			this->Text = L"View Transcript";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTranscript))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}

		void buttonViewTranscript_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ studentID = textBoxStudentID->Text;
			String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";
			MySqlConnection^ sqlConn = gcnew MySqlConnection(connectionString);
			try
			{
				sqlConn->Open();
				String^ query = "SELECT * FROM grades WHERE studentID = @studentID";
				MySqlCommand^ sqlCmd = gcnew MySqlCommand(query, sqlConn);
				sqlCmd->Parameters->AddWithValue("@studentID", studentID);
				MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter(sqlCmd);
				DataTable^ sqlDt = gcnew DataTable();
				sqlDta->Fill(sqlDt);
				dataGridViewTranscript->DataSource = sqlDt;
				sqlConn->Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
		}

		void buttonDownload_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "CSV file (*.csv)|*.csv";
			saveFileDialog->Title = "Save Transcript";
			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filePath = saveFileDialog->FileName;
				try
				{
					System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(filePath);
					for (int i = 0; i < dataGridViewTranscript->Columns->Count; i++)
					{
						sw->Write(dataGridViewTranscript->Columns[i]->HeaderText);
						if (i < dataGridViewTranscript->Columns->Count - 1)
						{
							sw->Write(",");
						}
					}
					sw->WriteLine();
					for (int i = 0; i < dataGridViewTranscript->Rows->Count; i++)
					{
						for (int j = 0; j < dataGridViewTranscript->Columns->Count; j++)
						{
							sw->Write(dataGridViewTranscript->Rows[i]->Cells[j]->Value);
							if (j < dataGridViewTranscript->Columns->Count - 1)
							{
								sw->Write(",");
							}
						}
						sw->WriteLine();
					}
					sw->Close();
					MessageBox::Show("Transcript downloaded successfully.");
				}
				catch (Exception^ ex)
				{
					MessageBox::Show(ex->Message);
				}
			}
		}
	};
}
