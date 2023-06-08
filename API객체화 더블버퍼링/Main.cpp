#include "Main.h"

//기본 메인 함수
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