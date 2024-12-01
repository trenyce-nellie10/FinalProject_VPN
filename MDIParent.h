#pragma once

namespace UniversityRecords {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MDIParent : public System::Windows::Forms::Form
    {
    public:
        MDIParent(void)
        {
            InitializeComponent();
        }

    protected:
        ~MDIParent()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        MenuStrip^ menuStrip;
        ToolStrip^ toolStrip;
        ToolStripMenuItem^ newToolStripMenuItem;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void);
        void newToolStripMenuItem_Click(Object^ sender, EventArgs^ e);
    };
}
