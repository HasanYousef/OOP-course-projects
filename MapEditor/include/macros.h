#pragma once

const int NUM_OF_TYPES = 7,
TEXTURE_SIZE = 16,
PANEL_WIDTH = 200;

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