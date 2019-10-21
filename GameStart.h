#pragma once
#include"Board.h"
class GameStart {
public:
	void start(Board & B) {
		B.installBoard();
	}
};