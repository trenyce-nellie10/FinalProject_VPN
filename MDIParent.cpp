#include "MDIParent.h"
#include "StudentForm.h"
#include "FacultyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MDIParent());
}

void MDIParent::InitializeComponent() {
    this->menuStrip = gcnew MenuStrip();
    this->toolStrip = gcnew ToolStrip();
    this->studentToolStripMenuItem = gcnew ToolStripMenuItem();
    this->facultyToolStripMenuItem = gcnew ToolStripMenuItem();

    this->menuStrip->Items->AddRange(gcnew cli::array<ToolStripItem^> { this->studentToolStripMenuItem, this->facultyToolStripMenuItem });
    this->studentToolStripMenuItem->Text = L"&Student";
    this->facultyToolStripMenuItem->Text = L"&Faculty";

    this->studentToolStripMenuItem->Click += gcnew EventHandler(this, &MDIParent::studentToolStripMenuItem_Click);
    this->facultyToolStripMenuItem->Click += gcnew EventHandler(this, &MDIParent::facultyToolStripMenuItem_Click);

    this->Controls->Add(this->menuStrip);
    this->Controls->Add(this->toolStrip);
    this->MainMenuStrip = this->menuStrip;
    this->IsMdiContainer = true;
    this->Text = L"University Records Management System";
}

void MDIParent::studentToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
    StudentForm^ studentForm = gcnew StudentForm();
    studentForm->MdiParent = this;
    studentForm->Show();
}

void MDIParent::facultyToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
    FacultyForm^ facultyForm = gcnew FacultyForm();
    facultyForm->MdiParent = this;
    facultyForm->Show();
}
