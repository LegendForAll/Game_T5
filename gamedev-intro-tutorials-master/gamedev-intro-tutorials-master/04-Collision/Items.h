#pragma once
#include "GameObject.h"
#include "define.h"
#include "Brick.h"

class Items : public CGameObject
{
	int currentAni = 0;
	int typeItem = I_MORNING_STAR;
	int equation_Fly = EQUATION_NORMAL;

public:

	Items();
	~Items();

	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects, vector<LPGAMEOBJECT> *coObjectStatic, vector<LPGAMEOBJECT> *coObjectEnemy);

	void Set_positionSimon(float _xSimon, float _ySimon);
	void Random_pre();
	void Set_epuationFly(int _equa) { this->equation_Fly = _equa; }
	void Set_typeItem(int _type) { this->typeItem = _type; }
};