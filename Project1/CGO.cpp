#include "CGO.h"

//constructor
CGO::CGO(int _Value, int _Pos_X, int _Pos_Y)
{
	Value = _Value;
	Pos_X = _Pos_X;
	Pos_Y = _Pos_Y;
}

//Getter
int CGO::GetGOValue(void) {
	return Value;
}

int CGO::GetPos_X(void) {
	return Pos_X;
}

int CGO::GetPos_Y(void) {
	return Pos_Y;
}

