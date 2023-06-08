#pragma once
#include <Windows.h>
#include "MainWindow.h"

//���� Ŭ����
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
	//������ ����
	void Init() {
		MainWindow::GetInstance()->BuildWindow();
	}
	int Run() {
		MSG Message;
		//���� �Լ��� �ִ� ����
		//getmessage�� �ƴ϶� peekmessage�϶� ��׶��忡�� �޼����� �������� ������ ���ؼ� �Ѱ���
		while (GetMessage(&Message, NULL, 0, 0)) {
			MainWindow::GetInstance()->Run(&Message);
		}
		return (int)Message.wParam;
	}
};

