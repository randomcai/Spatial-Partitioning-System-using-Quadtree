#pragma once
class CGO
{
private :
	int Value;
	int Pos_X;
	int Pos_Y;

public:
	//constructor
	CGO(int _Value, int _Pos_X, int _Pos_Y);

	//Getter functions
	int GetGOValue(void);
	int GetPos_X(void);
	int GetPos_Y(void);
	
};

