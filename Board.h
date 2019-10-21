#pragma once
#include "Cell.h"
class Board {
protected:
public:
	int OnOff;
	Cell arrCell[8][8];
	Cell *selectCell;
	int playerColor;

	Board();
	void installBoard();
	void DisplayBoards();
	void moveCursor(int &, int&, int&, int&);
	friend GameStart;
};