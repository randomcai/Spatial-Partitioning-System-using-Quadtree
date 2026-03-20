#include "CQuad.h"

//Constructor
CQuad::CQuad()
{
	Level = 0;
	NoOfCGO = 0;
	Type = "Unkown";
	Width = 0;
	Height = 0;
	for (int i = 0; i < 2; i++) {
		Origin[i] = -1;
		Max[i] = -1;
	}
	for (int i = 0; i < maxgo; i++) {
		AListCGO[i] = nullptr;
	}
	UpL = nullptr;
	UpR = nullptr;
	BotL = nullptr;
	BotR = nullptr;
}

//For Creating Root Only

void CQuad::CreateRoot(int _WorldX, int _WorldY, int _Origin[2])
{
	//setting Root data
	Origin[0] = _Origin[0];
	Origin[1] = _Origin[1];
	Max[0] = Origin[0] + _WorldX - 1;
	Max[1] = Origin[1] + _WorldY - 1;
	Width = _WorldX;
	Height = _WorldY;
	Type = "Root";
}

//getter functions

string CQuad::GetType(void) const {
	return Type;
}

int CQuad::GetNoOfCGO(void) const {
	return NoOfCGO;
}

int CQuad::GetWidth(void) const {
	return Width;
}

int CQuad::GetHeight(void) const {
	return Height;
}

int CQuad::GetOrigin(int _OriginAID) const {
	return Origin[_OriginAID];
}

int CQuad::GetLevel(void) const {
	return Level;
}

int CQuad::GetMax(int _MaxAID) const
{
	return Max[_MaxAID];
}


CQuad* CQuad::GetBotL(void) const {
	return BotL;
}

CQuad* CQuad::GetBotR(void) const {
	return BotR;
}

CQuad* CQuad::GetUpL(void) const {
	return UpL;
}

CQuad* CQuad::GetUpR(void)const {
	return UpR;
}

CGO* CQuad::GetAListofCGO(int _CGOAID) const {
	return AListCGO[_CGOAID];
}

//setter functions

void CQuad::SetType(string _Type) {
	Type = _Type;
}

void CQuad::SetNoOfCGO(int _NoOfCGO) {
	NoOfCGO = _NoOfCGO;
}

void CQuad::SetWidthNHeightNOrigin(CQuad* Parent)
{
	//Parent Origin
	int ParentOriginX = Parent->GetOrigin(0);//x
	int ParentOriginY = Parent->GetOrigin(1);//y
	//Width = X
	if (Type == "UpL" or Type == "BotL") {
		Origin[0] = ParentOriginX;//Setting X cords
		Width = Parent->GetWidth() / 2;
	}
	else if (Type == "UpR" or Type == "BotR") {
		if (Parent->GetWidth() % 2 == 1) {//odd Width
			Width = Parent->GetWidth() / 2 + 1;
			Origin[0] = ParentOriginX + Width - 1;
		}
		else {//even
			Width = Parent->GetWidth() / 2;
			Origin[0] = ParentOriginX + Width;
		}
	}
	//Height = Y
	if (Type == "UpL" or Type == "UpR") {
		Origin[1] = ParentOriginY;
		Height = Parent->GetHeight() / 2;
	}
	else if (Type == "BotL" or Type == "BotR") {
		if (Parent->GetHeight() % 2 == 1) {//odd Height
			Height = Parent->GetHeight() / 2 + 1;
			Origin[1] = ParentOriginY + Height - 1;
		}
		else { //even
			Height = Parent->GetHeight() / 2;
			Origin[1] = ParentOriginY + Height;
		}
	}
	Max[0] = Origin[0] + Width - 1;//CQuad max x cord
	Max[1] = Origin[1] + Height - 1;//CQuad max Y cord
}

void CQuad::SetLevel(int _ParentLevel)
{
	Level = _ParentLevel + 1;
}

void CQuad::SetUpL(CQuad* _UpL) {
	UpL = _UpL;
}

void CQuad::SetUpR(CQuad* _UpR) {
	UpR = _UpR;
}

void CQuad::SetBotL(CQuad* _BotL) {
	BotL = _BotL;
}

void CQuad::SetBotR(CQuad* _BotR) {
	BotR = _BotR;
}

void CQuad::AddCGOintoA(int _CGOAID, CGO* _NewCGO)
{
		AListCGO[_CGOAID] = _NewCGO;
}

