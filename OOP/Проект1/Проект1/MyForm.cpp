#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms; 

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	������1::MyForm form;
	Application::Run(%form);
}