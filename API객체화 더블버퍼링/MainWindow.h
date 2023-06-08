#pragma once
#include <Windows.h>
#include "DoubleBuffer.h"
#include "Mouse.h"

class MainWindow
{
	HWND windowhwnd;
	HINSTANCE  windowinstance;
	static MainWindow* Instance;
	MainWindow();
	~MainWindow();
public:
	static void Create(HINSTANCE hInstance) {
		if (Instance == NULL)
			Instance = new MainWindow;
		Instance->windowinstance = hInstance;
		Mouse::Create();
	}
	static MainWindow* GetInstance() {
		return Instance;
	}
	static void Destroy() {
		if (Instance == NULL)
			return;
		delete Instance;
		Instance = nullptr;
		Mouse::Destroy();
	}
	
	//�޽��� �ް� �Ѱ���
	void Run(MSG* _Message) {
		TranslateMessage(_Message);
		DispatchMessage(_Message);
	}
	void BuildWindow();

	//������ ���ν���
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam) {
		HDC hdc;
		PAINTSTRUCT ps;
		RECT crt;
		static DoubleBuffer* buffer;
		switch (iMessage) {
		case WM_CREATE:
			GetClientRect(hWnd, &crt);
			SetTimer(hWnd, 1, 10, NULL);
			buffer = new DoubleBuffer(hWnd, crt);
			buffer->Init();
			return 0;
		case WM_TIMER:
			InvalidateRect(hWnd, NULL, false);
			return 0;
		case WM_LBUTTONDOWN:
			Mouse::GetInstance()->SetClick(true);
			return 0;
		case WM_LBUTTONUP:
			Mouse::GetInstance()->SetClick(false);
			return 0;
		case WM_MOUSEMOVE:
			if (Mouse::GetInstance()->GetClick())//���콺 ��Ŭ�� �Ҷ��� ��ǥ ����
				Mouse::GetInstance()->SetPos(lParam);
			return 0;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			DrawBitmap(hdc, 0, 0, buffer->GetBit());
			EndPaint(hWnd, &ps);
			return 0;
		case WM_DESTROY:
			//����
			PostQuitMessage(0);
			return 0;

		}
		return(DefWindowProc(hWnd, iMessage, wParam, lParam));
	}
};

