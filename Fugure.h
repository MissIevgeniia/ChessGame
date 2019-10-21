#pragma once
class GameStart;
class Board; 
class Fugure
{
protected:
	char Name;
	int Color;
	int Step;
public:
	Fugure(char c = 0, int i = 0);
	virtual bool MoveFigure(Board *, int, int, int, int, int) = 0;
	char GetName();
	int GetColor();
	bool GetStep();
	void MakeStep();
	friend GameStart;
	friend Board;
};