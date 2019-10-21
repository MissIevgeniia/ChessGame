#include "Cell.h"
#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
void Cell::SetArrCell(int Y, int X, Fugure * F)
{
	Fig = F;
	y = Y;
	x = X;
}

void Cell::DelFigure()
{
	Fig = NULL;
}

Fugure & Cell::GetPtrFigure()
{
	return *Fig;
}



Cell::~Cell()
{
	if (Fig) delete Fig;
}

bool Cell::operator==(const Cell & C)
{
	if (x == C.x&&y == C.y) return 1;
	else return 0;
}

void Cell::Move(int a)
{
	if (a == 72 && y > 0) y--;
	else if (a == 80 && y < 7)y++;
	else if (a == 75 && x > 0) x--;
	else if (a == 77 && x < 7)x++;
}

void Cell::GetXY(int & X, int & Y)
{
	X = x;
	Y = y;
}

void Cell::moveFigure(Cell & C)
{
	Fig = &C.GetPtrFigure();
	C.DelFigure();
}

void Cell::Print(int x, int y)
{
	for (int Y = 0; Y < 3; Y++) {
		for (int X = 0; X < 3; X++) {
		gotoxy(x * 3 + X, y * 3 + Y);
		if (Y == 1 && X == 1 && Fig) 
			cout << Fig->GetName();
		else cout << ' ';
		}
		}
}
