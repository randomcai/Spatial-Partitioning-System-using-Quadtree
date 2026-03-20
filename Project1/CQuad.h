#pragma once
#include "CGO.h"
#include <iostream>
#define maxgo 20 //assuming the max allowed is 20

using namespace std;
class CQuad
{
private:

	int NoOfCGO;
	int Width;//X
	int Height;//Y
	int Origin[2];
	int Max[2];
	int Level;
	string Type;

	CGO* AListCGO[maxgo];

	CQuad* UpL;
	CQuad* UpR;
	CQuad* BotL;
	CQuad* BotR;

public:

	//constructor

	CQuad();

	//For Creating Root Only

	void CreateRoot(int _WorldX, int _WorldY, int _Origin[2]);

	//Getter Function

	string GetType(void) const;
	int GetNoOfCGO(void) const;
	int GetWidth(void) const;
	int GetHeight(void) const;
	int GetOrigin(int _OriginAID) const;
	int GetLevel(void) const;
	int GetMax(int _MaxAID) const;

	CQuad* GetUpL(void) const;
	CQuad* GetUpR(void) const;
	CQuad* GetBotL(void) const;
	CQuad* GetBotR(void) const;
	CGO* GetAListofCGO(int _CGOAID)const;

	//Setter Function

	void SetType(string _Type);
	void SetNoOfCGO(int _NoOfCGO);
	void SetLevel(int _ParentLevel);
	void SetWidthNHeightNOrigin(CQuad* Parent);
	void AddCGOintoA(int _CGOAID, CGO* _NewCGO);

	void SetUpL(CQuad* _UpL);
	void SetUpR(CQuad* _UpR);
	void SetBotL(CQuad* _BotL);
	void SetBotR(CQuad* _BotR);
};
