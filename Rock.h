#pragma once
#include"Fugure.h"
class Rock :public Fugure {
public:
	Rock(int c) :Fugure('R', c) {}
	bool MoveFigure(Board * B, int x, int y, int x1, int y1, int playerColor); 
};