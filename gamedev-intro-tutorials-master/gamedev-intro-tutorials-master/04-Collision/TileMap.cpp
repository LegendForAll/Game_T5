#include "TileMap.h"

TileMap::TileMap()
{

}

TileMap::TileMap(LPCWSTR filename)
{
	//load resource candle
	textures = CTextures::GetInstance();
	//textures->Add(ID_TEX_MAP1, L"textures\\lv1.png", D3DCOLOR_XRGB(255, 0, 255));
	//textures->Add(ID_TEX_MAP1, filename, D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_MAP2, filename, D3DCOLOR_XRGB(255, 0, 255));

}

TileMap::~TileMap()
{

}


void TileMap::LoadMap()
{
	int tilex, tiley;
	int x, y;
	int tilenum;

	//Viewport (0,0)
	tilex = 0;
	tiley = 0;

	RECT r1;
	D3DXVECTOR3 pos;
	//LPDIRECT3DTEXTURE9 texBG = textures->Get(ID_TEX_MAP1);
	LPDIRECT3DTEXTURE9 texBG = textures->Get(ID_TEX_MAP2);


	for (y = 0; y < MAPHEIGHT; y++)
	{
		for (x = 0; x < MAPWIDTH; x++)
		{
			//retrieve the tile number from this position
			//tilenum = MAPDATA_1[((tiley + y) * MAPWIDTH + (tilex + x))];

			tilenum = MAPDATA_2[((tiley + y) * MAPWIDTH + (tilex + x))];

			r1.left = (tilenum % MAPWIDTH) * TILEWIDTH;
			r1.top = (tilenum / MAPWIDTH) * TILEHEIGHT;
			r1.right = r1.left + TILEWIDTH;
			r1.bottom = r1.top + TILEHEIGHT;

			pos.x = x * TILEWIDTH;
			pos.y = y * TILEHEIGHT;
			pos.z = 0;

			matrix[y][x] = r1;
		}
	}
}

void TileMap::Render(LPD3DXSPRITE spriteHandler)
{

	float colStart = ViewPortX / TILEWIDTH;
	float colEnd = (ViewPortX / TILEWIDTH + SCREEN_WIDTH / TILEWIDTH + 1) > MAPWIDTH ? MAPWIDTH : (ViewPortX / TILEWIDTH + SCREEN_WIDTH / TILEWIDTH + 1);
	
	D3DXVECTOR3 pos(0,0,0);
	//LPDIRECT3DTEXTURE9 texBG = textures->Get(ID_TEX_MAP1);
	LPDIRECT3DTEXTURE9 texBG2 = textures->Get(ID_TEX_MAP2);

	for (int y = 0; y < 12; y++)//6
	{
		for (int x = colStart; x < colEnd; x++)
		{
			pos.x = x * TILEWIDTH - ViewPortX;
			pos.y = (y * TILEHEIGHT + TILEHEIGHT) - ViewPortY;
			pos.z = 0;
			spriteHandler->Draw(texBG2, &matrix[y][x], NULL, &pos, D3DCOLOR_XRGB(255, 255, 255));
		}
	}
}

void TileMap::UpdateScrollPosition()
{
	const int GAMEWORLDWIDTH = TILEWIDTH * MAPWIDTH;
	const int GAMEWORLDHEIGHT = TILEHEIGHT * MAPHEIGHT;

	//update horizontal scrolling position and speed
	ViewPortX += SpeedX;

	if (ViewPortX < 0)
	{
		ViewPortX = 0;
		SpeedX = 0;
	}
	else if (ViewPortX > GAMEWORLDWIDTH - WINDOWWIDTH)
	{
		ViewPortX = GAMEWORLDWIDTH - WINDOWWIDTH;
		SpeedX = 0;
	}

	//update vertical scrolling position and speed
	ViewPortY += SpeedY;
	if (ViewPortY < 0)
	{
		ViewPortY = 0;
		SpeedY = 0;
	}
	else if (ViewPortY > GAMEWORLDHEIGHT - WINDOWHEIGHT)
	{
		ViewPortY = GAMEWORLDHEIGHT - WINDOWHEIGHT;
		SpeedY = 0;
	}
}
