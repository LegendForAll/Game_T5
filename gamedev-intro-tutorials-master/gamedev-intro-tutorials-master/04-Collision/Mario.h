#pragma once
#include "GameObject.h"
#include "Whip.h"

#define SM_WALKING_SPEED		0.1f 
//0.1f
#define SM_JUMP_SPEED_Y			0.65f
#define SM_JUMP_DEFLECT_SPEED	0.2f
#define SM_GRAVITY				0.002f

#define SM_NOMAL				1

#define SM_BBOX_WIDTH			40
#define SM_BBOX_HEIGHT			66



class CMario : public CGameObject
{
	int level;
	int untouchable;
	DWORD untouchable_start;

	//weapon
	Whip *whip = new Whip();

	//Current Animation
	int ani = SM_STAND_STATIC;

	//Flags
	bool isAttack = false;
	bool isGround = true;
	bool isLeft = true;
	bool isEatItem = false;

	//Item 
	Items *item;

	//LPDIRECT3DTEXTURE9 texture;		//texture SIMON
	//CSprites * sprites;				//Manager sprite SIMON
	//CAnimations * animation;		//Manager animation SIMON

public: 
	CMario() : CGameObject()
	{
		level = SM_NOMAL;
		untouchable = 0;
		whip->LoadResource();
	}

	void LoadAnimation();
	virtual void LoadResource();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects , vector<LPGAMEOBJECT> *coObjectStatic , vector<LPGAMEOBJECT> *coObjectEnemy);
	virtual void Render(float xViewport, float yViewport);
	void SetState(int state);
	void SetLevel(int l) { level = l; }
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }
	void SetItem(Items *_item) { this->item = _item; }

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void CheckKey();
	void KeyEventHandler();
};