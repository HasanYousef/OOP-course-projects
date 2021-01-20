#pragma once

//---------------------
const char FONT_PATH[27] = "C:/Windows/Fonts/Arial.ttf";

//---------------------
const int WINDOW_WIDTH = 640,
WINDOW_HEIGHT = 500,
TEXTURE_SIZE = 32,
NUM_OF_TYPES = 8,
INIT_HEALTH = 3,
BUTTON_WIDTH = 160,
BUTTON_HEIGHT = 50,
BUTTON_MARGIN = 15,
ANIMATION_SIZE = 5,
ANIMATION_IMAGE_COUNT = 5;

const float ANIMATION_SWITCH_TIME = 0.2,
            SPEED = 0.2f;


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
	O_Enemy
};

//---------------------
//board chars
const char
SPACE = ' ',
WALL = '#',
LADDER = 'H',
ROPE = '-',
COIN = '*',
PLAYER = '@',
ENEMY = '%';