#pragma once

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RosterView
	/// </summary>
	public ref class RosterView : public System::Windows::Forms::Form
	{
	public:
		RosterView(void)
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
		~RosterView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ courseID;
	private: System::Windows::Forms::Button^ getRoster;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->courseID = (gcnew System::Windows::Forms::TextBox());
			this->getRoster = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(168, 145);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"courseID";
			// 
			// courseID
			// 
			this->courseID->Location = System::Drawing::Point(268, 139);
			this->courseID->Name = L"courseID";
			this->courseID->Size = System::Drawing::Size(212, 26);
			this->courseID->TabIndex = 1;
			// 
			// getRoster
			// 
			this->getRoster->Location = System::Drawing::Point(286, 219);
			this->getRoster->Name = L"getRoster";
			this->getRoster->Size = System::Drawing::Size(147, 27);
			this->getRoster->TabIndex = 2;
			this->getRoster->Text = L"Get Roster";
			this->getRoster->UseVisualStyleBackColor = true;
			// 
			// RosterView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(735, 325);
			this->Controls->Add(this->getRoster);
			this->Controls->Add(this->courseID);
			this->Controls->Add(this->label1);
			this->Name = L"RosterView";
			this->Text = L"RosterView";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
