#include "StateTwo.h"

StateTwo::StateTwo()
{

}

StateTwo::~StateTwo()
{

}

void StateTwo::InitState(LPDIRECT3DDEVICE9 dv, LPDIRECT3DSURFACE9 bb)
{
	tilemap = new TileMap(L"textures\\lv2.png");
	tilemap->ViewPort();
	tilemap->LoadMap();
}

void StateTwo::LoadState()
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
	for (int i = 0; i <= 100; i++)
	{
		CBrick *brick = new CBrick();
		brick->LoadResource();
		brick->SetPosition(0 + i * 32.0f, 410.0f);
		brick->SetState(GROUND);
		//objects.push_back(brick);
		objecttsStatic.push_back(brick);
	}

	//Candle small H1
	for (int i = 1; i <= 4; i++)
	{
		CandleSmall *can = new CandleSmall();
		can->LoadResource();
		can->SetPosition(i * 255.0f, 280.0f);
		can->SetState(CANDLESMALL_STATE_NO);
		objecttsStatic.push_back(can);

	}

	//Candle small H2
	CandleSmall *can = new CandleSmall();
	can->LoadResource();
	can->SetPosition(345.0f, 350.0f);
	can->SetState(CANDLESMALL_STATE_NO);
	objecttsStatic.push_back(can);

	for (int i = 1; i <= 4; i++)
	{
		CandleSmall *can = new CandleSmall();
		can->LoadResource();
		can->SetPosition(i * 258.0f + 345.0f, 350.0f);
		can->SetState(CANDLESMALL_STATE_NO);
		objecttsStatic.push_back(can);

	}

	for (int i = 0; i <= 2; i++)
	{
		CBrick *brick = new CBrick();
		brick->LoadResource();
		brick->SetPosition(1380 + i * 32, 287);
		brick->SetState(GROUND);
		//objects.push_back(brick);
	}
	//Limit map
	CLimit *lim = new CLimit();
	lim->SetPosition(0.0f, 0.0f);
	lim->SetState(LIMIT_CAMERA);
	objects.push_back(lim);

	CLimit *lim1 = new CLimit();
	lim1->SetPosition(5600, 0.0f);
	lim->SetState(LIMIT_CAMERA);
	objects.push_back(lim1);

	CLimit *limG2 = new CLimit();
	limG2->SetPosition(1500, 225.0f);
	limG2->SetState(LIMIT_GROUND);
	objects.push_back(limG2);

	//Ground
	for (int i = 0; i < 4; i++)
	{
		CLimit *limG1 = new CLimit();
		limG1->SetPosition(0.0f + i*1000, 410);
		limG1->SetState(LIMIT_GROUND);
		objects.push_back(limG1);
	}

	//Zombie
	Zombie *zom1 = new Zombie();
	zom1->SetPosition(600, 345.0f);
	zom1->LoadResource();
	zom1->SetNX(-1);
	zom1->SetSpeed(0.05f, 1.0f);
	zom1->SetState(ZOMBIE_MOVE_LEFT);
	zom1->SetlimX(600);
	zom1->SetSlimX(500);
	objectsEnemy.push_back(zom1);

	Zombie *zom2 = new Zombie();
	zom2->SetPosition(1000, 345.0f);
	zom2->LoadResource();
	zom2->SetNX(-1);
	zom2->SetSpeed(0.05f, 1.0f);
	zom2->SetState(ZOMBIE_MOVE_LEFT);
	zom2->SetlimX(1000);
	zom2->SetSlimX(300);
	objectsEnemy.push_back(zom2);

	//Panther
	Panther *pan1 = new Panther();
	pan1->LoadResource();
	pan1->SetPosition(550, 340);
	pan1->SetNX(-1);
	pan1->SetState(PANTHER_STATIC);
	objectsEnemy.push_back(pan1);

	Panther *pan2 = new Panther();
	pan2->LoadResource();
	pan2->SetPosition(800, 340);
	pan2->SetNX(-1);
	pan2->SetState(PANTHER_STATIC);
	objectsEnemy.push_back(pan2);
}

void StateTwo::UpdateState(DWORD dt)
{
	CGameState::UpdateState(dt);
}

void StateTwo::RenderState(LPDIRECT3DDEVICE9 d3ddv, LPDIRECT3DSURFACE9 bb, LPD3DXSPRITE spriteHandler)
{
	//Update viewport
	tilemap->UpdateScrollPosition();
	CGameState::RenderState(d3ddv, bb, spriteHandler);
}