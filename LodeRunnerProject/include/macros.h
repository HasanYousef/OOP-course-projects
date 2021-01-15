#pragma once

//---------------------
const char MAP_PATH[11] = "C:map.txt",
FONT_PATH[27] = "C:/Windows/Fonts/Arial.ttf";

//---------------------
const int WINDOW_WIDTH = 640,
WINDOW_HEIGHT = 500,
NUM_OF_TYPES = 8,
INIT_HEALTH = 3,
SPEED = 0.1,
BUTTON_WIDTH = 120,
BUTTON_HEIGHT = 50,
ANIMATION_SIZE = 5,
ANIMATION_IMAGE_COUNT = 5;

const float ANIMATION_SWITCH_TIME = 0.2;

//---------------------
enum UserOption
{
	MainMenu,
	StartGame,
	EditMaps,
	Exit,
	AddSpace,
	AddWall,
	AddLadder,
	AddRope,
	AddMoney,
	AddPlayer,
	AddEnemy,
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
	O_Player,
	O_Enemy,
	O_Coin,
	O_Gift
};

//---------------------
//board chars
const char
SPACE = ' ',
WALL = '#',
LADDER = 'H',
ROPE = '-',
MONEY = '*',
PLAYER = '@',
ENEMY = '%';