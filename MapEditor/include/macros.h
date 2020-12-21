#pragma once

const int NUM_OF_TYPES = 7,
TEXTURE_SIZE = 16,
BOARD_UI_X = 200,
TEXTSIZE = 20,
SAVE_BUTTON = 0,
CLEAR_BUTTON = 1;

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

//board chars
const char
SPACE = ' ',
WALL = '#',
LADDER = 'H',
ROPE = '-',
MONEY = '*',
PLAYER = '@',
ENEMY = '%';