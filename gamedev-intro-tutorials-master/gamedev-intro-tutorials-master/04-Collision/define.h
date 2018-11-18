#pragma once
//Window
#define WINDOW_CLASS_NAME					L"SampleWindow"
#define MAIN_WINDOW_TITLE					L"Castlevania"
#define BACKGROUND_COLOR D3DCOLOR_XRGB		(0, 0, 0)
#define MAX_FRAME_RATE						90

//Map state
#define FULLSCREEN							false
#define SCREEN_WIDTH						640
#define SCREEN_HEIGHT						480
#define TILE_WIDTH							64
#define TILE_HEIGHT							64

#define ID_TEX_MAP1							100
#define MAPWIDTH_1							24
#define MAPHEIGHT_1							6

#define ID_TEX_MAP2							200
#define MAPWIDTH_2							88
#define MAPHEIGHT_2							12

#define SAFE_DELETE(p) \
if(p) \
{\
	delete (p); \
	p = nullptr; \
} \

//Flight equation
#define EQUATION_NORMAL		1
#define EQUATION_SIN		2
#define EQUATION_PARAPOL	3

enum eSoundID
{
	USING_WHIP,
	SLASH_WATER,
	SELECT,
	PAUSE,
	OPEN_DOOR,
	HOLY_WATER,
	HOLY_CROSS,
	HIT_CANNON,
	HIT_SOUND,
	FALLING_DOWN_WATER_SUFACE,
	FALLING,
	DECREASE_WEAPON_USE_POINT,
	COLLECT_WEAPON,
	COLLECT_ITEM,
	BOSS_BATTLE_POISON_MIND,
	GAME_OVER,
	GAME_START_PROLOGUE,
	LIFE_LOST,
	STAGE_01_VAMPIRE_KILLER,
	STAGE_04_STALKER,
	STAGE_CLEAR,
	TITLE_THEME_PRELUDE,
	GO_INTO_CASTLE,
	SIMON_HURTED,
	EAT_CHANGE_STATE_BALL,
	MONEY
};


//Texture
#define ID_TEX_BBOX				-100
#define ID_TEX_MISC				10
#define ID_LEVEL_ONE_BG			20
#define ID_TEX_SIMON			30
#define ID_TEX_WHIP				40
#define ID_TEX_CANDLE			50
#define ID_TEX_DEAD				60
#define ID_TEX_GROUND			70
#define ID_TEX_ZOMBIE			80
#define ID_TEX_PANTHER			90
#define ID_TEX_CANDLE_SMALL		100
#define ID_TEX_KNIFE			110

#define ID_ITEM_HEART_BIG		61
#define ID_ITEM_MORNING_STAR	62
#define ID_ITEM_MONEY_BLUE		63
#define ID_ITEM_ROSARY			64
#define ID_ITEM_ROSACT			65
#define ID_ITEM_STOPWATCH		66
#define ID_ITEM_DOUBLE_SHOT		67
#define ID_ITEM_BALL			68


//Status SIMON
#define SM_STAND_STATIC			0
#define SM_MOVE_LEFT			1
#define SM_SIT					2
#define SM_JUMP					3
#define SM_STAND_ATTACK			4
#define SM_SIT_ATTACK			5
#define SM_STAND_UP_STAIR		6
#define SM_STAND_DOWN_STAIR		7
#define SM_MOVE_UP_STAIR		8
#define SM_MOVE_DOWN_STAIR		9
#define SM_ATTACK_UP_STAIR		10
#define SM_ATTACK_DOWN_STAIR	11
#define SM_HURTED				12
#define SM_INVISIBLE			13
#define SM_EAT_ITEM				14
#define SM_FALL_DOWN			15
#define SM_THROW_WEAPON			16
#define SM_DEAD					17
#define SM_STAND_BACK			18
#define SM_FLY_ATTACK			19

//Weapons
#define WP_WHIP_STAND_LEFT		19
#define WP_WHIP_SIT_LEFT		20
#define WP_KNIFE_STAND			0
#define WP_KNIFE_SIT			1

//Speed weapons
#define KNIFE_SPEED				0.1f

//Items

#define I_HEART_BIG				0
#define I_MORNING_STAR			1
#define I_MONEY_BLUE			2
#define I_ROSARY				3
#define I_ROSACT				4
#define I_STOPWATCH				5
#define I_DOUBLE_SHOT			6
#define I_BOSS_BAT				7

//ALL BOX
#define CANDLE_BBOX_WIDTH		32
#define CANDLE_BBOX_HEIGHT		64
#define PROP_BBOX_WIDTH			35
#define PROP_BBOX_HEIGHT		35
#define PROP_BBOX_CHANGE		100
#define GROUND_BBOX_WIDTH		32
#define GROUND_BBOX_HEIGHT		32
#define BRICK_BBOX_WIDTH		760
#define BRICK_BBOX_HEIGHT		32
#define LIMITCAM_BBOX_WIDTH		20
#define LIMITCAM_BBOX_HEIGHT	480
#define LIMIT_GROUND_WIDTH		1000
#define LIMIT_GROUND_HEIGHT		32
#define LIMIT_GROUND_H2			400
#define ZOMBIE_BBOX_WIDTH		34
#define ZOMBIE_BBOX_HEIGHT		64
#define ITEM_BBOX_WIDTH			32
#define ITEM_BBOX_HEIGHT		32
#define PANTHER_BBOX_WIDTH		64
#define PANTHER_BBOX_HEIGHT		32
#define CANDLESMALL_BBOX_WIDTH	16
#define CANDLESMALL_BBOX_HEIGHT 16
#define KNIFE_BBOX_WIDTH		32
#define KNIFE_BBOX_HEIGHT		18

//Status candle
#define CANDLE_STATE_NO			100
#define CANDLE_STATE_DIE		200
#define CANDLESMALL_STATE_NO	0
#define CANDLESMALL_STATE_DIE	1

//Ground
#define BRICK					0
#define GROUND					1

//Transparent object
#define LIMIT_CAMERA			0
#define LIMIT_GROUND			1

//Enemy
#define ZOMBIE_MOVE_LEFT		0
#define ZOMBIE_DIE				1
#define PANTHER_STATIC			0
#define PANTHER_JUMP			1
#define PANTHER_MOVE			2
#define PANTHER_DIE				3

//Distance enemy attack
#define DIS_PANTHER_ATTACK		200.0f
