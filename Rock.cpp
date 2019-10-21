#include "Rock.h"
#include"Board.h"
#include <windows.h>

bool Rock::MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor)
{
	{
		if (x != x1 && y != y1)return 0;
		Fugure*ptrFigure;
		if (x == x1) {
			int a = abs(y - y1) - 1;
			if (y < y1) {
				while (a) {
					ptrFigure = &B->arrCell[y + a][x].GetPtrFigure();
					if (ptrFigure != 0) return 0;
					a--;
				}
				ptrFigure = &B->arrCell[y1][x].GetPtrFigure();
				if (ptrFigure && playerColor == ptrFigure->GetColor()) return 0;
				return 1;
			}
			if (y > y1) {
				while (a) {
					ptrFigure = &B->arrCell[y - a][x].GetPtrFigure();
					if (ptrFigure != 0) return 0;
					a--;
				}
				ptrFigure = &B->arrCell[y1][x].GetPtrFigure();
				if (ptrFigure && playerColor == ptrFigure->GetColor()) return 0;
				return 1;
			}
		}
		if (y == y1) {
			int a = abs(x - x1) - 1;
			if (x < x1) {
				while (a) {
					ptrFigure = &B->arrCell[y][x + a].GetPtrFigure();
					if (ptrFigure != 0) return 0;
					a--;
				}
				ptrFigure = &B->arrCell[y][x1].GetPtrFigure();
				if (ptrFigure && playerColor == ptrFigure->GetColor()) return 0;
				return 1;
			}
			if (x > x1) {
				while (a) {
					ptrFigure = &B->arrCell[y][x - a].GetPtrFigure();
					if (ptrFigure != 0) return 0;
					a--;
				}
				ptrFigure = &B->arrCell[y][x1].GetPtrFigure();
				if (ptrFigure && playerColor == ptrFigure->GetColor()) return 0;
				return 1;
			}
		}
		else return 0;
	}
}
