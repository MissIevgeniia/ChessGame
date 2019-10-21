#pragma once
#include"Fugure.h"
class Horse :public Fugure {
public:
	Horse(int c) :Fugure('H', c) {}
	bool MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor);
};