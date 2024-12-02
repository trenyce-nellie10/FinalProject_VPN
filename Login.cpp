#include "Login.h"

using namespace System;
using namespace System::Windows::Forms;
int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FinalProjectVPN::Login form;
	Application::Run(% form);
	
}

