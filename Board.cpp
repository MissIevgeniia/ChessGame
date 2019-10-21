#include "Board.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include"Pawn.h"
#include"Bishop.h"
#include"Rock.h"
#include"Horse.h"
#include"Queen.h"
#include"King.h"
using namespace std;
void gotoxy(short x, short y);
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

Board::Board()
{
	selectCell = new Cell;
	selectCell->SetArrCell(4, 4);
	playerColor = 7;
}

void Board::installBoard()
{
	OnOff = 1;
	for (int i = 0; i < 8; i++) {
		for (int x = 0; x < 8; x++) {
			if (i == 0 || i == 1) {
				if (i == 0) {
					if (x == 0 || x == 7) arrCell[i][x].SetArrCell(i, x, new Rock(6));
					if (x == 1 || x == 6) arrCell[i][x].SetArrCell(i, x, new Horse(6));
					if (x == 2 || x == 5) arrCell[i][x].SetArrCell(i, x, new Bishop(6));
					if (x == 3)arrCell[i][x].SetArrCell(i, x, new Queen(6));
					if (x == 4)arrCell[i][x].SetArrCell(i, x, new King(6));
				}
				else arrCell[i][x].SetArrCell(i, x, new Pawn(6));
			}
			else if (i >= 2 && i <= 5) arrCell[i][x].SetArrCell(i, x);
			else {
				if (i == 7) {
					if (x == 0 || x == 7) arrCell[i][x].SetArrCell(i, x, new Rock(7));
					if (x == 1 || x == 6) arrCell[i][x].SetArrCell(i, x, new Horse(7));
					if (x == 2 || x == 5) arrCell[i][x].SetArrCell(i, x, new Bishop(7));
					if (x == 3)arrCell[i][x].SetArrCell(i, x, new Queen(7));
					if (x == 4)arrCell[i][x].SetArrCell(i, x, new King(7));
				}
				else arrCell[i][x].SetArrCell(i, x, new Pawn(7));
			}
		}
	}
}

void Board::DisplayBoards()
{
	Fugure*ptrFigure;
	int kings = 0, winner = 0, g;
	while (true) {
		system("cls");
		gotoxy(30, 15);
		if (playerColor == 7) cout << "White turn\n";
		else cout << "Black turn\n";
		gotoxy(26, 18);
		cout << "Press space to finish the game";
		for (int i = 0; i < 8; i++) {
			for (int x = 0; x < 8; x++) {
				ptrFigure = &arrCell[i][x].GetPtrFigure();
				if (ptrFigure&&ptrFigure->GetName() == 'K') {
					kings++;
					if (ptrFigure->GetColor() == 7) winner--;
					if (ptrFigure->GetColor() == 6) winner++;
				}
				if (*selectCell == arrCell[i][x]) {
					if (ptrFigure) {
						SetColor(ptrFigure->GetColor(), 12);
						arrCell[i][x].Print(x, i);
					}
					else {
						SetColor(7, 12);
						arrCell[i][x].Print(x, i);
					}
					SetColor(7, 0);
				}
				else if ((i + x) % 2) {
					if (ptrFigure) {
						SetColor(ptrFigure->GetColor(), 15);
						arrCell[i][x].Print(x, i);
					}
					else {
						SetColor(7, 15);
						arrCell[i][x].Print(x, i);
					}
				}
				else {
					if (ptrFigure) {
						SetColor(ptrFigure->GetColor(), 0);
						arrCell[i][x].Print(x, i);
					}
					else {
						SetColor(7, 0);
						arrCell[i][x].Print(x, i);
					}
				}
			}
			cout << endl;
		}
		g = _getch();
		if (kings < 2) {
			if (winner < 0)OnOff = -2;
			else OnOff = -1;
		}
		if (g == 32) {
			OnOff = 0;
			break;
		}
		else if (g == 13) break;
		else selectCell->Move(g);
	}
}

void Board::moveCursor(int &x, int &y, int &x1, int& y1)
{
	selectCell->GetXY(x, y);
	DisplayBoards();
	selectCell->GetXY(x1, y1);
	Fugure*PtrFigure;
	PtrFigure = &arrCell[y][x].GetPtrFigure();
	if (PtrFigure->MoveFigure(this, x, y, x1, y1, playerColor)) {
		arrCell[y1][x1].moveFigure(arrCell[y][x]);
		if (playerColor == 7) playerColor = 6;
		else playerColor = 7;
	}
}
