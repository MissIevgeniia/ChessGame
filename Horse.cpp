#include "Horse.h"
#include"Board.h"
#include <windows.h>

bool Horse::MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor)
{
	Fugure*ptrFigure = &B->arrCell[y1][x1].GetPtrFigure();
	if (ptrFigure && playerColor == ptrFigure->GetColor()) return 0;
	if (abs(x - x1) == 2 && abs(y - y1) == 1) return 1;
	if (abs(x - x1) == 1 && abs(y - y1) == 2) return 1;
	else return 0;
}
