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
	/// Summary for PayFees
	/// </summary>
	public ref class PayFees : public System::Windows::Forms::Form
	{
	public:
		PayFees(void)
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
		~PayFees()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4; // Label for Amount
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2; // TextBox for Amount
	private: System::Windows::Forms::ComboBox^ comboBox1;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label()); // Initialize label4
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox()); // Initialize textBox2
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(69, 140);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Student ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(69, 229);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Payment Method ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(287, 37);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(243, 37);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Fees Payment ";
			this->label3->Click += gcnew System::EventHandler(this, &PayFees::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(69, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Amount";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(242, 402);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 32);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PayFees::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(240, 140);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(240, 180);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 7;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"card", L"cash", L"momo"
			});
			this->comboBox1->Location = System::Drawing::Point(240, 229);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 28);
			this->comboBox1->TabIndex = 5;
			// 
			// PayFees
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 571);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"PayFees";
			this->Text = L"PayFees";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int studentID = Convert::ToInt32(this->textBox1->Text);
		double amount = Convert::ToDouble(this->textBox2->Text);
		String^ paymentMethod = this->comboBox1->SelectedItem->ToString();
		String^ paymentDate = DateTime::Now.ToString("yyyy-MM-dd");

		// Database connection string
		String^ connectionString = "Server=localhost;Database=university;Uid=root;Pwd='';";

		// SQL query to insert the payment details
		String^ query = "INSERT INTO Payments (studentID, amount, paymentMethod, paymentDate) VALUES (@StudentID, @Amount, @PaymentMethod, @PaymentDate)";

		// Create a connection to the database
		MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
		MySqlCommand^ command = gcnew MySqlCommand(query, connection);

		// Add parameters to the SQL query
		command->Parameters->AddWithValue("@StudentID", studentID);
		command->Parameters->AddWithValue("@Amount", amount);
		command->Parameters->AddWithValue("@PaymentMethod", paymentMethod);
		command->Parameters->AddWithValue("@PaymentDate", paymentDate);

		try
		{
			// Open the connection
			connection->Open();

			// Execute the query
			command->ExecuteNonQuery();

			// Show a success message
			MessageBox::Show("Payment Successful", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
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

