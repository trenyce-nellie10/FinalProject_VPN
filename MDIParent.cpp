#include "MDIParent.h"
#include "ChildForm.h"

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
    this->newToolStripMenuItem = gcnew ToolStripMenuItem();
    this->menuStrip->Items->AddRange(gcnew cli::array<ToolStripItem^> { this->newToolStripMenuItem });
    this->newToolStripMenuItem->Text = L"&New";
    this->newToolStripMenuItem->Click += gcnew EventHandler(this, &MDIParent::newToolStripMenuItem_Click);
    this->Controls->Add(this->menuStrip);
    this->Controls->Add(this->toolStrip);
    this->MainMenuStrip = this->menuStrip;
    this->IsMdiContainer = true;
    this->Text = L"MDI Parent Form";
}

void MDIParent::newToolStripMenuItem_Click(Object^ sender, EventArgs^ e) {
    ChildForm^ childForm = gcnew ChildForm();
    childForm->MdiParent = this;
    childForm->Show();
}
