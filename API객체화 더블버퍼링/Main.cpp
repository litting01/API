#include "Main.h"

//�⺻ ���� �Լ�
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	CMain::Create(hInstance); 
	CMain::GetInstance()->Init();
	int result = CMain::GetInstance()->Run();
	return result;
}
CMain* CMain::Instance = nullptr;
CMain::CMain() {}
CMain::~CMain() {}