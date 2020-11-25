#pragma once

#include "Enemy.h"

//---get---enemy---indexes---------------------
Coord Enemy::get_coord() const
{
	return m_coord;
}

//---------------------------------------------
Coord Enemy::move(const Board& board)
{
	int boardSize = board.get_size();
	int leftLen = NO_PATH,
		rightLen = NO_PATH,
		upLen = NO_PATH,
		downLen = NO_PATH;
	vector <vector<bool>> helpBoard;
	for (int row = 0; row < boardSize; row++) {
		vector <bool> temp;
		for (int col = 0; col < boardSize; col++) {
			temp.push_back(false);
		}
		helpBoard.push_back(temp);
	}
	Coord lefCoord(m_coord.m_col - 1, m_coord.m_row),
		rightCoord(m_coord.m_col + 1, m_coord.m_row),
		upCoord(m_coord.m_col, m_coord.m_row - 1),
		downCoord(m_coord.m_col, m_coord.m_row + 1);
	leftLen = find_shortest_path(board, helpBoard, lefCoord, RIGHT);
	rightLen = find_shortest_path(board, helpBoard, rightCoord, LEFT);
	upLen = find_shortest_path(board, helpBoard, upCoord, DOWN);
	downLen = find_shortest_path(board, helpBoard, downCoord, UP);

	int shortest = leftLen;
	Coord bestDir = lefCoord;
	if (rightLen < shortest) {
		shortest = rightLen;
		bestDir = rightCoord;
	}
	if (upLen < shortest) {
		shortest = upLen;
		bestDir = upCoord;
	}
	if (downLen < shortest) {
		shortest = downLen;
		bestDir = downCoord;
	}

	if (shortest == NO_PATH)
		return m_coord;
	return bestDir;
}


int Enemy::find_shortest_path(const Board& board, vector<vector<bool>>& helpBoard, const Coord& curr, int fromDir)
{
	char currChar = board.get_char(board.get_ground(curr));
	if(currChar == WALL || currChar == EMPTY)
}