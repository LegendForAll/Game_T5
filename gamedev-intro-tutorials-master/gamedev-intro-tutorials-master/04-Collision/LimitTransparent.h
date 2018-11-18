#pragma once
#include "GameObject.h"



class CLimit : public CGameObject
{
	//int currentAni = LM_LEFT_1;

public:
	virtual void LoadResource();
	virtual void Render(float xViewport, float yViewport);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};