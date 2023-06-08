#include "DoubleBuffer.h"

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	//비트맵을 그릴 메모리 dc를 그림
	MemDC = CreateCompatibleDC(hdc);
	//본래 비트맵값을 저장
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	//비트맵의 크기를 가져옴
	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	//본래 비트맵으로 전환
	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}