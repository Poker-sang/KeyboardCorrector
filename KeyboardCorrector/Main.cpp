#define new gcnew
using namespace System::Windows;
using namespace System::Windows::Controls;
using namespace System::Windows::Media;

[System::STAThreadAttribute]

int main(array<System::String^>^ args)
{
	auto ap = new Application();
	auto w = new Window();
	ap->Run(w);
	return 0;
}