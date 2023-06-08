#pragma once
#include <Windows.h>
#include "MainWindow.h"

//메인 클래스
class CMain {
	static CMain* Instance;
	CMain();
	~CMain();
public:
	static void Create(HINSTANCE hInstance) {
		if (Instance == NULL)
			Instance = new CMain;
		MainWindow::Create(hInstance);
	}
	static CMain* GetInstance() {
		return Instance;
	}
	static void Destroy() {
		MainWindow::Destroy();
		if (Instance == NULL)
			return;
		delete Instance;
		Instance = nullptr;
	}
	//윈도우 생성
	void Init() {
		MainWindow::GetInstance()->BuildWindow();
	}
	int Run() {
		MSG Message;
		//메인 함수에 있는 이유
		//getmessage가 아니라 peekmessage일때 백그라운드에서 메세지를 전달할지 말지를 정해서 넘겨줌
		while (GetMessage(&Message, NULL, 0, 0)) {
			MainWindow::GetInstance()->Run(&Message);
		}
		return (int)Message.wParam;
	}
};

