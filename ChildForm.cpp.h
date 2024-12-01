#pragma once

namespace UniversityRecords {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class ChildForm : public System::Windows::Forms::Form
    {
    public:
        ChildForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~ChildForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        DataGridView^ dataGridView1;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void);
        void ChildForm_Load(Object^ sender, EventArgs^ e);
    };
}
#pragma once
