#pragma once

const int WINDOW_WIDTH = 640,
WINDOW_HEIGHT = 500,
NUM_OF_TYPES = 7,
TEXTURE_SIZE = 32,
BOARD_UI_X = 120,
TEXTSIZE = 5,
SAVE_BUTTON = 0,
CLEAR_BUTTON = 1,
BUTTON_WIDTH = 119,
BUTTON_HEIGHT = 50;
//---------------------
enum ObjectType
{
	Space,
	Wall,
	Ladder,
	Rope,
	Money,
	Player,
	Enemy
};
//---------------------
enum ActionType
{
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
//board chars
const char
SPACE = ' ',
WALL = '#',
LADDER = 'H',
ROPE = '-',
MONEY = '*',
PLAYER = '@',
ENEMY = '%';

const char FONT_PATH[27] = "C:/Windows/Fonts/Arial.ttf";