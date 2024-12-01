#pragma once

namespace UniversityRecords {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class FacultyForm : public System::Windows::Forms::Form
    {
    public:
        FacultyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~FacultyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        DataGridView^ dataGridView1;
        Button^ verifyButton;
        System::ComponentModel::Container ^components;

        void InitializeComponent(void);
        void FacultyForm_Load(Object^ sender, EventArgs^ e);
        void verifyButton_Click(Object^ sender, EventArgs^ e);
    };
}
