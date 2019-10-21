#pragma once
#include "Fugure.h"
class Pawn :public Fugure {
public:
	Pawn(int c) :Fugure('P', c) {}
	bool MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor);
};