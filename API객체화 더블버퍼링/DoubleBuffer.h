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
		//복사 붙여넣기할 비트맵이 비어 있으면 생성
		db_bit = CreateCompatibleBitmap(hdc, db_rt.right, db_rt.bottom);
		//그림 그릴 dc 생성
		HDC hMemDC = CreateCompatibleDC(hdc);
		//본래 비트맵값을 저장
		HBITMAP OldBit = (HBITMAP)SelectObject(hMemDC, db_bit);
		//배경을 하얀색으로 색칠
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
