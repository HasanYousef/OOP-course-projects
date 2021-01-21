#pragma once

//---------------------
const char FONT_PATH[27] = "C:/Windows/Fonts/Arial.ttf";

//---------------------
const int WINDOW_WIDTH = 1200,
WINDOW_HEIGHT = 900,
TEXTURE_SIZE = 32,
NUM_OF_TYPES = 9,
INIT_HEALTH = 3,
BUTTON_WIDTH = 160,
BUTTON_HEIGHT = 50,
BUTTON_MARGIN = 15,
ANIMATION_SIZE = 5,
ANIMATION_IMAGE_COUNT = 5,
NUM_OF_SOUNDS = 3;

const float ANIMATION_SWITCH_TIME = 0.2,
            SPEED = 0.1f;


//---------------------
enum UserOption
{
	AddSpace,
	AddWall,
	AddLadder,
	AddRope,
	AddCoin,
	AddGift,
	AddPlayer,
	AddEnemy,
	MainMenu,
	StartGame,
	EditMaps,
	AddNewMap,
	Exit,
	SaveBoard,
	ClearBoard,
	NextBoard,
	PrevBoard,
	Nothing
};

//---------------------
enum ObjectType
{
	O_Space,
	O_Wall,
	O_Ladder,
	O_Rope,
	O_Coin,
	O_Gift,
	O_Player,
	O_Enemy,
	O_Well   //added
};

enum SoundType
{
	GetHit,
	GetCoin,
	Theme
};

//---------------------
//board chars
const char
SPACE = ' ',
WALL = '#',
LADDER = 'H',
ROPE = '-',
COIN = '*',
GIFT = '+',
PLAYER = '@',
ENEMY = '%';