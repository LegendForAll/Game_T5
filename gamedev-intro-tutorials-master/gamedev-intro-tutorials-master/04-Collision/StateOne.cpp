#include "StateOne.h"

StateOne::StateOne()
{

}

StateOne::~StateOne()
{

}

void StateOne::InitState(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb)
{
	tilemap = new TileMap(L"textures\\lv1.png");
	tilemap->ViewPort();
	tilemap->LoadMap();
}

void StateOne::LoadState()
{
	CGameState::LoadState();

	//Simon
	simon = new CMario();
	simon->LoadResource();
	simon->SetPosition(50.0f, 0);
	simon->SetState(SM_STAND_STATIC);
	objects.push_back(simon);

	Items *_it = new Items();
	_it->LoadResource();
	_it->SetPosition(200, 100);
	_it->SetState(I_MORNING_STAR);
	_it->SetInvisible(true);
	_it->SetDead(true);
	objects.push_back(_it);

	//add item for simon
	simon->SetItem(_it);

	//Groud
	CBrick *brick = new CBrick();
	brick->LoadResource();
	brick->SetPosition(0, 390);
	objects.push_back(brick);

	CBrick *brick1 = new CBrick();
	brick1->LoadResource();
	brick1->SetPosition(735, 390);
	objects.push_back(brick1);

	//Candle
	Candle *candle = new Candle();
	candle->LoadResource();
	candle->SetPosition(200.0f, 330);
	objecttsStatic.push_back(candle);

	Candle *candle1 = new Candle();
	candle1->LoadResource();
	candle1->SetPosition(450.0f, 330);
	objecttsStatic.push_back(candle1);

	Candle *candle2 = new Candle();
	candle2->LoadResource();
	candle2->SetPosition(700.0f, 330);
	objecttsStatic.push_back(candle2);

	Candle *candle3 = new Candle();
	candle3->LoadResource();
	candle3->SetPosition(950.0f, 330);
	objecttsStatic.push_back(candle3);

	//Limit map
	CLimit *lim = new CLimit();
	lim->SetPosition(0.0f, 0.0f);
	objects.push_back(lim);

	CLimit *lim1 = new CLimit();
	lim1->SetPosition(1390, 0.0f);
	objects.push_back(lim1);
}

void StateOne::UpdateState(DWORD dt)
{
	CGameState::UpdateState(dt);
}

void StateOne::RenderState(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler)
{
	//Update viewport
	tilemap->UpdateScrollPosition();
	CGameState::RenderState(d3ddv, bb, spriteHandler);
}
