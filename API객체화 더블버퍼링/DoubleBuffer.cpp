#include "DoubleBuffer.h"

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	//��Ʈ���� �׸� �޸� dc�� �׸�
	MemDC = CreateCompatibleDC(hdc);
	//���� ��Ʈ�ʰ��� ����
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	//��Ʈ���� ũ�⸦ ������
	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	//���� ��Ʈ������ ��ȯ
	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}