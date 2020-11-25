#pragma once

//Board.txt directory
const char BOARD_PATH[] = "C:\\Users\\hasan\\Desktop\\OOP-course-projects\\LodeRunner\\src\\Board.txt";

//game consts
const int NUM_OF_LEVELS = 2,
INIT_HEALTH = 3;

//directions
const int
NO_MOVE = 0,
UP = 1,
RIGHT = 2,
DOWN = 3,
LEFT = 4,
NO_PATH = -1;

//player movment keyboard consts
const int KB_UP = 72,
KB_DOWN = 80,
KB_LEFT = 75,
KB_RIGHT = 77;

//board chars
const char
EMPTY = ' ',
WALL = '#',
PLAYER = '@',
LADDER = 'H',
PLAYER_ON_LADDER = 'S',
ENEMY = '%',
MONEY = '*',
ROPE = '-';

//UI
const char BOTTOM_LINE[] = "_______________________________";