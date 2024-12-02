#pragma once

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(void)
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
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	
		MenuStrip^ menuStrip;
		ToolStrip^ toolStrip;
		ToolStripMenuItem^ studentToolStripMenuItem;
		ToolStripMenuItem^ facultyToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void);
		//void studentToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
		//void facultyToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
	
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Size = System::Drawing::Size(300, 300);
			this->Text = L"Dashboard";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;

		}
#pragma endregion
	};
}
