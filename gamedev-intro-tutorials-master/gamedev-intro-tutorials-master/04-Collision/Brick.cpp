#include "Brick.h"

void CBrick::LoadResource()
{
	//load resource
	CTextures * textures = CTextures::GetInstance();
	textures->Add(ID_TEX_MISC, L"Resource\\sprites\\ground_test.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_GROUND, L"Resource\\sprites\\Ground\\Brick.png", D3DCOLOR_XRGB(176, 224, 248));

	CSprites * sprites = CSprites::GetInstance();
	LPDIRECT3DTEXTURE9 texMisc = textures->Get(ID_TEX_MISC);
	LPDIRECT3DTEXTURE9 texGround = textures->Get(ID_TEX_GROUND);

	sprites->Add(20001, 0, 0, 768, 32, texMisc);
	sprites->Add(20002, 0, 0, 32, 32, texGround);

	LPANIMATION ani;
	CAnimations * animations = CAnimations::GetInstance();

	//Animation ground
	ani = new CAnimation(100);		// brick
	ani->Add(20001);
	animations->Add(601, ani);


	ani = new CAnimation(100);		// ground
	ani->Add(20002);
	animations->Add(602, ani);

	this->AddAnimation(601);
	this->AddAnimation(602);
}

void CBrick::Render(float xViewport, float yViewport)
{
	this->X_view = x - xViewport;
	this->Y_view = y - yViewport;

	switch (this->state)
	{
		case BRICK:
		{
			animations[BRICK]->Render(x - xViewport, y - yViewport);
			break;
		}
		case GROUND:
		{
			animations[GROUND]->Render(x - xViewport, y - yViewport);
			break;
		}
	}
	//animations[0]->Render(x - xViewport,y - yViewport);
	RenderBoundingBox();
}

void CBrick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;

	switch (this->state)
	{
		case BRICK:
		{
			r = x + BRICK_BBOX_WIDTH;
			b = y + BRICK_BBOX_HEIGHT;
			break;
		}
		case GROUND:
		{
			r = x + GROUND_BBOX_WIDTH;
			b = y + GROUND_BBOX_HEIGHT;
			break;
		}
	}


}