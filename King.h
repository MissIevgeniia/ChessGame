#pragma once
#include"Fugure.h"
class King :public Fugure {
public:
	King(int c) :Fugure('K', c) {}
	bool MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor);
};