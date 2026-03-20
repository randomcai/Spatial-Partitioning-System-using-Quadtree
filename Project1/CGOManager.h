#pragma once
#include "CGO.h"
#include "CQuad.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
//delete that when done
class CGOManager
{
private:

	//variables

	int WorldX;
	int WorldY;
	int WorldOrigin[2];
	int CGOCounter;

	CGO* ACGOList[maxgo];

	CQuad* RootObj;

	//functions

	void SortCGO(CQuad* _Quad);
	void AddCGO();
	void PrintNearbyGO(void);

	void PreOrderForSorting(CQuad* _Quad);
	void PreOrderForPrinting(CQuad* _Quad);
	bool PreOrderForFindingCGO(CGO* _CGO, CQuad* _Quad, bool Done);
	void PostOrderForDeleting(CQuad* _Quad);
public:
	//constructor n destructor
	CGOManager();
	~CGOManager();

	//start program
	void StartProgram(void);
};

