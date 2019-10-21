#pragma once
#include"Fugure.h"
class Bishop :public Fugure {
public:
	Bishop(int c) :Fugure('B', c) {}
	bool MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor);
};