#include "Bishop.h"
#include"Board.h"
#include <windows.h>

bool Bishop::MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor)
{
	Fugure*ptrFigure = &B->arrCell[y1][x1].GetPtrFigure();
	if (ptrFigure && playerColor == ptrFigure->GetColor()) return 0;
	if (abs(x - x1) != abs(y - y1)) return 0;
	int a = abs(x - x1) - 1;
	if (x < x1&&y < y1) {
		while (a) {
			ptrFigure = &B->arrCell[y + a][x + a--].GetPtrFigure();
			if (ptrFigure != 0) return 0;
		}
		return 1;
	}
	if (x < x1&&y > y1) {
		while (a) {
			ptrFigure = &B->arrCell[y - a][x + a--].GetPtrFigure();
			if (ptrFigure != 0) return 0;
		}
		return 1;
	}
	if (x > x1&&y < y1) {
		while (a) {
			ptrFigure = &B->arrCell[y + a][x - a--].GetPtrFigure();
			if (ptrFigure != 0) return 0;
		}
		return 1;
	}
	if (x > x1&&y > y1) {
		while (a) {
			ptrFigure = &B->arrCell[y - a][x - a--].GetPtrFigure();
			if (ptrFigure != 0) return 0;
		}
		return 1;
	}
	return 0;
}
