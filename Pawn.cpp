#include "Pawn.h"
#include"Board.h"

bool Pawn::MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor)
{
	Fugure*ptrFigure = &B->arrCell[y1][x1].GetPtrFigure();
	if (playerColor == 6 && y1 < y) return 0;
	if (playerColor == 7 && y1 > y) return 0;
	if (y1 == y) return 0;
	if (x1 != x) {
		if (ptrFigure == 0) return 0;
		if (x1 - x == 1 || x - x1 == 1) {
			if (playerColor == ptrFigure->GetColor()) return 0;
			MakeStep();
			return 1;
		}
	}
	if (ptrFigure != 0) return 0;
	if (y1 - y == 1 || y - y1 == 1) {
		MakeStep();
		return 1;
	}
	if ((y1 - y == 2 || y - y1 == 2) && (GetStep())) {
		MakeStep();
		return 1;
	}
	return 0;
}
