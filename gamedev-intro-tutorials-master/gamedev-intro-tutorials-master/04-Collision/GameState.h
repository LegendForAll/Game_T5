#pragma once
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "debug.h"
#include "define.h"
#include "Game.h"
#include "GameObject.h"
#include "Textures.h"

#include "Mario.h"
#include "Brick.h"
#include "Goomba.h"
#include "Candle.h"
#include "CandleSmall.h"
#include "Zombie.h"
#include "Panther.h"
#include "Items.h"
#include "LimitTransparent.h"

class CGameState
{
public:

	CMario *simon;

	TileMap *tilemap = new TileMap();
	bool marioInView = false;

	DWORD dt;
	vector<LPGAMEOBJECT> objects;
	vector<LPGAMEOBJECT> objecttsStatic;
	vector<LPGAMEOBJECT> objectsEnemy;

public:

	CGameState();
	~CGameState();

	virtual void InitState(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb);
	virtual void LoadState();
	virtual void UpdateState(DWORD dt);
	virtual void RenderState(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler);

};