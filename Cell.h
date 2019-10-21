#pragma once
#include "Fugure.h"
class Cell {
	int x;
	int y;
	Fugure * Fig;
public:
	void SetArrCell(int Y, int X, Fugure * F = 0);
	void DelFigure();
	Fugure & GetPtrFigure();
	~Cell();
	bool operator==(const Cell & C);
	void Move(int a);
	void GetXY(int &X, int &Y);
	void moveFigure(Cell & C);
	void Print(int x, int y);
};
