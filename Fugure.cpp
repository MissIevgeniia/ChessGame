#include "Fugure.h"

Fugure::Fugure(char c, int i)
{
	Step = 0;
	Name = c;
	Color = i;
}

char Fugure::GetName()
{
	return Name;
}

int Fugure::GetColor()
{
	return Color;

}

bool Fugure::GetStep()
{
	if (Step) return false;
	else return true;
}

void Fugure::MakeStep()
{
	Step++;
}
