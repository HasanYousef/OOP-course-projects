#pragma once

//---------------------
const char MAP_PATH[11] = "C:map.txt",
FONT_PATH[27] = "C:/Windows/Fonts/Arial.ttf";

//---------------------
const int WINDOW_WIDTH = 640,
WINDOW_HEIGHT = 500,
TEXTURE_SIZE = 32,
NUM_OF_TYPES = 7,
INIT_HEALTH = 3,
BOARD_UI_X = 32,
SPEED = 0.1;

//---------------------
enum MainMenuOption
{
	StartGame,
	EditMaps,
	Exit
};

//---------------------
enum ObjectType
{
	O_Space,
	O_Wall,
	O_Ladder,
	O_Rope,
	O_Money,
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
MONEY = '*',
PLAYER = '@',
ENEMY = '%';