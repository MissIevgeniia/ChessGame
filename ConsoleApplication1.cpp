#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Board.h"
#include"GameStart.h"
using namespace std;
class GameStart;
class Board;
class Cell;
class Board;
class GameStart;
class Pawn;
class Rock;
class Horse;
class Bishop;
class Queen;
class King;


void main()
{
	int x, y, X1, Y1;
	GameStart Game;
	Board board;
	Game.start(board);
	while (board.OnOff) {
		board.DisplayBoards();
		if (board.OnOff <= 0) break;
		board.moveCursor(x, y, X1, Y1);
	}
	cout << "Game Over" << endl;
	if (board.OnOff == -2) cout << "White is the winner!" << endl;
	else if (board.OnOff == -1) cout << "Black is the winner!" << endl;
}