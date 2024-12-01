#pragma once

namespace UniversityRecords {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class StudentForm : public System::Windows::Forms::Form
    {
    public:
        StudentForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~StudentForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        DataGridView^ dataGridView1;
        System::ComponentModel::Container ^components;

        void InitializeComponent(void);
        void StudentForm_Load(Object^ sender, EventArgs^ e);
    };
}
