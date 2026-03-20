#include "CGOManager.h"

//constructor n destructor

CGOManager::CGOManager() {
	WorldX = 25;
	WorldY = 25;
	CGOCounter = 0;
	RootObj = new CQuad();
	for (int i = 0; i < maxgo; i++) {
		ACGOList[i] = nullptr;
	}
	for (int i = 0; i < 2; i++) {
		WorldOrigin[i] = 0;
	}
}

CGOManager::~CGOManager() {
	PostOrderForDeleting(RootObj);
	for (int i = 0; i < CGOCounter; i++) {
		delete ACGOList[i];
		ACGOList[i] = nullptr;
	}
}

void CGOManager::SortCGO(CQuad* _Quad) {
	CQuad* Current = _Quad;
	int NumOfCGO = 0;
	if (Current->GetNoOfCGO() >3) {
		//creating quads
		for (int i = 0; i < 4; i++) {
			CQuad* Split = new CQuad();
			switch (i) {
			case 0://UpL
				Split->SetType("UpL");
				Current->SetUpL(Split);
				break;
			case 1://UpR
				Split->SetType("UpR");
				Current->SetUpR(Split);
				break;
			case 2://BotL
				Split->SetType("BotL");
				Current->SetBotL(Split);
				break;
			case 3://BotR
				Split->SetType("BotR");
				Current->SetBotR(Split);
				break;
			}
			Split->SetWidthNHeightNOrigin(Current);
			Split->SetLevel(Current->GetLevel());
		}
		//Sorting the CGOs to put at the correct CQuad	
		for (int i = 0; i < Current->GetNoOfCGO(); i++) {
			CQuad* AddingTo = nullptr;
			CGO* Temp = Current->GetAListofCGO(i);
			int TempX = Temp->GetPos_X();
			int TempY = Temp->GetPos_Y();
			if ((TempX >= Current->GetUpL()->GetOrigin(0)) and (TempX <= Current->GetUpL()->GetMax(0)) and
				(TempY >= Current->GetUpL()->GetOrigin(1)) and (TempY <= Current->GetUpL()->GetMax(1))) {
				AddingTo = Current->GetUpL();
			}//UPL [0]

			else if ((TempX >= Current->GetUpR()->GetOrigin(0)) and (TempX <= Current->GetUpR()->GetMax(0)) and
				(TempY >= Current->GetUpR()->GetOrigin(1)) and (TempY <= Current->GetUpR()->GetMax(1))) {
				AddingTo = Current->GetUpR();
			}//UPR [1]

			else if ((TempX >= Current->GetBotL()->GetOrigin(0)) and (TempX <= Current->GetBotL()->GetMax(0)) and
				(TempY >= Current->GetBotL()->GetOrigin(1)) and (TempY <= Current->GetBotL()->GetMax(1))) {
				AddingTo = Current->GetBotL();
			}//BOTL [2]

			else if ((TempX >= Current->GetBotR()->GetOrigin(0)) and (TempX <= Current->GetBotR()->GetMax(0)) and
				(TempY >= Current->GetBotR()->GetOrigin(1)) and (TempY <= Current->GetBotR()->GetMax(1))) {
				AddingTo = Current->GetBotR();
			}//BOTR [3]

			if (AddingTo != nullptr) {
				NumOfCGO = AddingTo->GetNoOfCGO();
				AddingTo->AddCGOintoA(NumOfCGO, Temp);
				AddingTo->SetNoOfCGO(++NumOfCGO);
			}
		}
		//Repeat till end of the GO LIST
	}
}

void CGOManager::PreOrderForSorting(CQuad* _Quad)
{
	if (_Quad != NULL) {
		SortCGO(_Quad);
		PreOrderForSorting(_Quad->GetUpL());
		PreOrderForSorting(_Quad->GetUpR());
		PreOrderForSorting(_Quad->GetBotL());
		PreOrderForSorting(_Quad->GetBotR());
	}
}

void CGOManager::PreOrderForPrinting(CQuad* _Quad) {
	if (_Quad != NULL) {
		if(_Quad->GetNoOfCGO()!=0){
			for (int i = 0; i < _Quad->GetLevel(); i++) {
				cout << "-";
			}
			cout << _Quad->GetLevel() << ": " << _Quad->GetType() << " (" << _Quad->GetOrigin(0) << ", " << _Quad->GetOrigin(1) << "), H"
				<< _Quad->GetHeight() << "W" << _Quad->GetWidth() << " (" << _Quad->GetNoOfCGO() << ")\n";
		}
		PreOrderForPrinting(_Quad->GetUpL());
		PreOrderForPrinting(_Quad->GetUpR());
		PreOrderForPrinting(_Quad->GetBotL());
		PreOrderForPrinting(_Quad->GetBotR());
	}
}

bool CGOManager::PreOrderForFindingCGO(CGO* _CGO, CQuad* _Quad,bool Done)
{
		bool PrintSurroundings = false;
		if (_Quad != NULL and Done ==false) {
			CGO* Temp = nullptr;
			for (int i = 0; i < _Quad->GetNoOfCGO(); i++) {
				Temp = _Quad->GetAListofCGO(i);
				if (Temp == _CGO) {
					if (_Quad->GetNoOfCGO() == 1) {//if its the only CGO in its quad
						cout << "There no nearby CGO\n";
						return true;
					}
					if (_Quad->GetNoOfCGO() < 4) {//there is only 3 CGO in its quad. Therefore no more higher lvl where that CGO is in
						PrintSurroundings = true;
					}
				}
			}
			if (PrintSurroundings) {
				bool First = true;
				for (int i = 0; i < _Quad->GetNoOfCGO(); i++) {
					if (_CGO != _Quad->GetAListofCGO(i)) {
						if (First == false) {
							cout << ",";
						}
						cout << " " << _Quad->GetAListofCGO(i)->GetGOValue();
						First = false;
					}
				}
				return true;//stop the recurring function
			}
			else{
				PreOrderForFindingCGO(_CGO, _Quad->GetUpL(),Done);
				PreOrderForFindingCGO(_CGO, _Quad->GetUpR(), Done);
				PreOrderForFindingCGO(_CGO, _Quad->GetBotL(), Done);
				PreOrderForFindingCGO(_CGO, _Quad->GetBotR(), Done);
			}
		}
	return false;
}

void CGOManager::PostOrderForDeleting(CQuad* _Quad)
{
	if (_Quad != NULL) {
		PostOrderForDeleting(_Quad->GetUpL());
		PostOrderForDeleting(_Quad->GetUpR());
		PostOrderForDeleting(_Quad->GetBotL());
		PostOrderForDeleting(_Quad->GetBotR());
		delete _Quad;
	}
}

void CGOManager::AddCGO() {
	std::ifstream inFile;
	inFile.open("go.txt");

	std::string temp;
	std::string _ID, _PosX, _PosY;
	int ID, PosX, PosY;
	while (std::getline(inFile, temp)) {
		std::stringstream TempSS1, TempSS2, TempSS3;
		std::stringstream ss(temp);
		std::getline(ss, _ID, ',');
		TempSS1 << _ID;
		TempSS1 >> ID;
		std::getline(ss, _PosX, ',');
		TempSS2 << _PosX;
		TempSS2 >> PosX;
		std::getline(ss, _PosY, ',');
		TempSS3 << _PosY;
		TempSS3 >> PosY;
		ACGOList[CGOCounter] = new CGO(ID, PosX, PosY);
		CGOCounter++;
	}
	inFile.close();

	RootObj->CreateRoot(WorldX, WorldY, WorldOrigin);
	int Temp = RootObj->GetNoOfCGO();
	for (int i = 0; i < CGOCounter; i++) {
		if(ACGOList[i]->GetPos_X() >= RootObj->GetOrigin(0) and ACGOList[i]->GetPos_X() <= RootObj->GetMax(0) and
			ACGOList[i]->GetPos_Y() >= RootObj->GetOrigin(1) and ACGOList[i]->GetPos_Y() <= RootObj->GetMax(1)) {
			RootObj->AddCGOintoA(i, ACGOList[i]);
			RootObj->SetNoOfCGO(++Temp);
		}//checking if the CGO is within the World Size
	}

}

void CGOManager::PrintNearbyGO(void) {
	int Input;
	cout << "Enter GO's ID:";
	cin >> Input;
	CGO* temp = nullptr;
	bool Found = false;
	for (int i = 0; i < RootObj->GetNoOfCGO(); i++) {
		temp = RootObj->GetAListofCGO(i);
		if (temp->GetGOValue() == Input) {
			Found = true;
			break;
		}
	}
	if (Found) {
		bool Done=false;
		cout << "GO(s) in the same quad:";
		Done= PreOrderForFindingCGO(temp, RootObj,Done);
		cout << endl;
	}
	else {
		cout << "GO not found!\n";
	}
}


//Start Function

void CGOManager::StartProgram(void) {
	AddCGO();
	PreOrderForSorting(RootObj);
	cout << endl;
	while (true)
	{
		int Input;
		cout << "\n[1]Print Tree\n[2]Print GOs in the same quad\n[3]Quit\nInput:";
		cin >> Input;
		if (Input == 1) {
			PreOrderForPrinting(RootObj);
		}
		else if (Input == 2) {
			PrintNearbyGO();
		}
		else if (Input == 3) {
			break;
		}
		else {
			cout << "Wrong Input Please Re-Enter Again!\n";
		}
	}
}


