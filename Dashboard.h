#pragma once
#include "EnrollmentForm.h"
#include "ViewGrades.h"
#include "PayFees.h"
#include "ViewSchedule.h"

namespace FinalProjectVPN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	private:
		void ConnectToDatabase()
		{
			// Add your database connection logic here
			// Example:
			String^ connectionString = "server=localhost;user id=root;password=;database=university;";
			MySqlConnection^ connection = gcnew MySqlConnection(connectionString);
			try
			{
				connection->Open();
				// Connection successful
			}
			catch (MySqlException^ ex)
			{
				MessageBox::Show("Error connecting to the database: " + ex->Message);
			}
		}
	public:
		Dashboard(void)
		{
			InitializeComponent();
			ConnectToDatabase();
			UpdateMenuBasedOnRole();
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


	private: System::Windows::Forms::MenuStrip^ menuStrip4;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ aDMINToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStrip^ toolStrip2;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::MenuStrip^ menuStrip3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^ enrollToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewGradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ payFeesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewScheduleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageCoursesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterGradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewClassRosterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ updateProfileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageStudentsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageCoursesToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ manageCoursesToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ generateReportsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageFinancialsToolStripMenuItem;

	protected:
		System::ComponentModel::Container^ components;

	private:
		String^ userId;
		String^ userRole;
		void UpdateMenuBasedOnRole()
		{
			if (userRole == "Student")
			{
				studentToolStripMenuItem->Checked = true;
				facultyToolStripMenuItem->Checked = false;
				aDMINToolStripMenuItem->Checked = false;
			}
			else if (userRole == "Faculty")
			{
				studentToolStripMenuItem->Checked = false;
				facultyToolStripMenuItem->Checked = true;
				aDMINToolStripMenuItem->Checked = false;
			}
			else if (userRole == "Admin")
			{
				studentToolStripMenuItem->Checked = false;
				facultyToolStripMenuItem->Checked = false;
				aDMINToolStripMenuItem->Checked = true;
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
			void InitializeComponent(void)
			{
				this->menuStrip3 = (gcnew System::Windows::Forms::MenuStrip());
				this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->enrollToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->viewGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->payFeesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->viewScheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->manageCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->enterGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->viewClassRosterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->updateProfileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->manageStudentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->manageCoursesToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->manageCoursesToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->generateReportsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->manageFinancialsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->menuStrip3->SuspendLayout();
				this->SuspendLayout();
				// 
				// menuStrip3
				// 
				this->menuStrip3->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
				this->menuStrip3->ImageScalingSize = System::Drawing::Size(24, 24);
				this->menuStrip3->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					this->toolStripMenuItem3,
						this->toolStripMenuItem4, this->toolStripMenuItem5
				});
				this->menuStrip3->Location = System::Drawing::Point(0, 0);
				this->menuStrip3->Name = L"menuStrip3";
				this->menuStrip3->Size = System::Drawing::Size(1115, 33);
				this->menuStrip3->TabIndex = 0;
				this->menuStrip3->Text = L"menuStrip3";
				// 
				// toolStripMenuItem3
				// 
				this->toolStripMenuItem3->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
					this->enrollToolStripMenuItem,
						this->viewGradesToolStripMenuItem, this->payFeesToolStripMenuItem, this->viewScheduleToolStripMenuItem
				});
				this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
				this->toolStripMenuItem3->Size = System::Drawing::Size(89, 29);
				this->toolStripMenuItem3->Text = L"Student";
				// 
				// enrollToolStripMenuItem
				// 
				this->enrollToolStripMenuItem->Name = L"enrollToolStripMenuItem";
				this->enrollToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->enrollToolStripMenuItem->Text = L"Enroll";
				this->enrollToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dashboard::enrollToolStripMenuItem_Click);
				// 
				// viewGradesToolStripMenuItem
				// 
				this->viewGradesToolStripMenuItem->Name = L"viewGradesToolStripMenuItem";
				this->viewGradesToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->viewGradesToolStripMenuItem->Text = L"View Grades";
				this->viewGradesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dashboard::viewGradesToolStripMenuItem_Click);
				// 
				// payFeesToolStripMenuItem
				// 
				this->payFeesToolStripMenuItem->Name = L"payFeesToolStripMenuItem";
				this->payFeesToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->payFeesToolStripMenuItem->Text = L"Pay Fees";
				this->payFeesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dashboard::payFeesToolStripMenuItem_Click);
				// 
				// viewScheduleToolStripMenuItem
				// 
				this->viewScheduleToolStripMenuItem->Name = L"viewScheduleToolStripMenuItem";
				this->viewScheduleToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->viewScheduleToolStripMenuItem->Text = L"View Schedule";
				this->viewScheduleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dashboard::viewScheduleToolStripMenuItem_Click);
				// 
				// toolStripMenuItem4
				// 
				this->toolStripMenuItem4->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
					this->manageCoursesToolStripMenuItem,
						this->enterGradesToolStripMenuItem, this->viewClassRosterToolStripMenuItem, this->updateProfileToolStripMenuItem
				});
				this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
				this->toolStripMenuItem4->Size = System::Drawing::Size(82, 29);
				this->toolStripMenuItem4->Text = L"Faculty";
				this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &Dashboard::toolStripMenuItem4_Click);
				// 
				// manageCoursesToolStripMenuItem
				// 
				this->manageCoursesToolStripMenuItem->Name = L"manageCoursesToolStripMenuItem";
				this->manageCoursesToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->manageCoursesToolStripMenuItem->Text = L"Manage Courses";
				// 
				// enterGradesToolStripMenuItem
				// 
				this->enterGradesToolStripMenuItem->Name = L"enterGradesToolStripMenuItem";
				this->enterGradesToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->enterGradesToolStripMenuItem->Text = L"Enter Grades";
				// 
				// viewClassRosterToolStripMenuItem
				this->viewClassRosterToolStripMenuItem->Name = L"viewClassRosterToolStripMenuItem";
				this->viewClassRosterToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->viewClassRosterToolStripMenuItem->Text = L"View Class Roster";
				// 
				// updateProfileToolStripMenuItem
				// 
				this->updateProfileToolStripMenuItem->Name = L"updateProfileToolStripMenuItem";
				this->updateProfileToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->updateProfileToolStripMenuItem->Text = L"Update Profile ";
				// 
				// toolStripMenuItem5
				// 
				this->toolStripMenuItem5->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
					this->manageStudentsToolStripMenuItem,
						this->manageCoursesToolStripMenuItem1, this->manageCoursesToolStripMenuItem2, this->generateReportsToolStripMenuItem, this->manageFinancialsToolStripMenuItem
				});
				this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
				this->toolStripMenuItem5->Size = System::Drawing::Size(81, 29);
				this->toolStripMenuItem5->Text = L"Admin";
				this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &Dashboard::toolStripMenuItem5_Click);
				// 
				// manageStudentsToolStripMenuItem
				// 
				this->manageStudentsToolStripMenuItem->Name = L"manageStudentsToolStripMenuItem";
				this->manageStudentsToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->manageStudentsToolStripMenuItem->Text = L"Manage Students ";
				// 
				// manageCoursesToolStripMenuItem1
				// 
				this->manageCoursesToolStripMenuItem1->Name = L"manageCoursesToolStripMenuItem1";
				this->manageCoursesToolStripMenuItem1->Size = System::Drawing::Size(270, 34);
				this->manageCoursesToolStripMenuItem1->Text = L"Manage Faculty ";
				this->manageCoursesToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Dashboard::manageCoursesToolStripMenuItem1_Click);
				// 
				// manageCoursesToolStripMenuItem2
				// 
				this->manageCoursesToolStripMenuItem2->Name = L"manageCoursesToolStripMenuItem2";
				this->manageCoursesToolStripMenuItem2->Size = System::Drawing::Size(270, 34);
				this->manageCoursesToolStripMenuItem2->Text = L"Manage Courses ";
				// 
				// generateReportsToolStripMenuItem
				// 
				this->generateReportsToolStripMenuItem->Name = L"generateReportsToolStripMenuItem";
				this->generateReportsToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->generateReportsToolStripMenuItem->Text = L"Generate Reports";
				// 
				// manageFinancialsToolStripMenuItem
				// 
				this->manageFinancialsToolStripMenuItem->Name = L"manageFinancialsToolStripMenuItem";
				this->manageFinancialsToolStripMenuItem->Size = System::Drawing::Size(270, 34);
				this->manageFinancialsToolStripMenuItem->Text = L"Manage Financials";
				this->manageFinancialsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Dashboard::manageFinancialsToolStripMenuItem_Click);
				// 
				// Dashboard
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(1115, 507);
				this->Controls->Add(this->menuStrip3);
				this->IsMdiContainer = true;
				this->MainMenuStrip = this->menuStrip3;
				this->Name = L"Dashboard";
				this->Text = L"Dashboard";
				this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
				this->menuStrip3->ResumeLayout(false);
				this->menuStrip3->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
	private: System::Void aDMINToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void menuStrip4_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}
	private: System::Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void enrollToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		EnrollmentForm^ enroll = gcnew EnrollmentForm();
		enroll->ShowDialog();
		this->Show();
	}
	private: System::Void toolStripMenuItem5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void manageCoursesToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void manageFinancialsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void viewGradesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		ViewGrades^ view = gcnew ViewGrades();
		view->ShowDialog();
		this->Show();
	}
	private: System::Void payFeesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		PayFees^ pay = gcnew PayFees();
		pay->ShowDialog();
		this->Show();
	}
	private: System::Void viewScheduleToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		ViewSchedule^ view = gcnew ViewSchedule();
		view->ShowDialog();
		this->Show();
	}
private: System::Void toolStripMenuItem4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
