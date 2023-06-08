#pragma once
#include <Windows.h>
#include "Mouse.h"

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit);

class DoubleBuffer {
	HWND db_hwnd;
	HBITMAP db_bit;
	RECT db_rt;
public:
	DoubleBuffer(HWND p_hwnd,RECT p_rt) {
		db_hwnd = p_hwnd;
		db_rt = p_rt;
	}
	void Init() {
		HDC hdc = GetDC(db_hwnd);
		//���� �ٿ��ֱ��� ��Ʈ���� ��� ������ ����
		db_bit = CreateCompatibleBitmap(hdc, db_rt.right, db_rt.bottom);
		//�׸� �׸� dc ����
		HDC hMemDC = CreateCompatibleDC(hdc);
		//���� ��Ʈ�ʰ��� ����
		HBITMAP OldBit = (HBITMAP)SelectObject(hMemDC, db_bit);
		//����� �Ͼ������ ��ĥ
		FillRect(hMemDC, &db_rt, (HBRUSH)GetStockObject(WHITE_BRUSH));
		SelectObject(hMemDC, OldBit);
		DeleteDC(hMemDC);
		ReleaseDC(db_hwnd, hdc);
	}
	HDC GetBackDC() {
		HDC hdc = GetDC(db_hwnd);
		HDC hMemDC = CreateCompatibleDC(hdc);
		HBITMAP hOldBit = (HBITMAP)SelectObject(hMemDC, db_bit);
		FillRect(hMemDC, &db_rt, (HBRUSH)GetStockObject(WHITE_BRUSH));
		ReleaseDC(db_hwnd, hdc);
		return hMemDC;
	}
	HBITMAP GetBit() { return db_bit; }
};
