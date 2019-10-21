#pragma once
#include"Fugure.h"
class Queen :public Fugure {
public:
	Queen(int c) :Fugure('Q', c) {}
	bool MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor);
};