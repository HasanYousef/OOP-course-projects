#pragma once

const int NUM_OF_TYPES = 6;

enum ObjectType
{
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