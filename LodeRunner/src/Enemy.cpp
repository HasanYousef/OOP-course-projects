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
	helpBoard[m_coord.m_row][m_coord.m_col] = true;
	leftLen = find_shortest_path(board, helpBoard, lefCoord);
	rightLen = find_shortest_path(board, helpBoard, rightCoord);
	upLen = find_shortest_path(board, helpBoard, upCoord);
	downLen = find_shortest_path(board, helpBoard, downCoord);

	int shortest = leftLen;
	Coord bestDir = lefCoord;
	if ((rightLen < shortest && rightLen != NO_PATH) || shortest == NO_PATH) {
		shortest = rightLen;
		bestDir = rightCoord;
	}
	if ((upLen < shortest && upLen != NO_PATH) || shortest == NO_PATH) {
		shortest = upLen;
		bestDir = upCoord;
	}
	if ((downLen < shortest && downLen != NO_PATH) || shortest == NO_PATH) {
		shortest = downLen;
		bestDir = downCoord;
	}

	if (shortest == NO_PATH)
		return m_coord;
	m_coord = board.get_ground(bestDir);
	return bestDir;
}


int Enemy::find_shortest_path(const Board& board, vector<vector<bool>>& helpBoard, const Coord& curr)
{
	char currChar = board.get_char(board.get_ground(curr));
	if (currChar == WALL || helpBoard[curr.m_row][curr.m_col])
		return NO_PATH;
	if (currChar == PLAYER || currChar == PLAYER_ON_LADDER)
		return 0;
	helpBoard[curr.m_row][curr.m_col] = true;
	int leftLen, rightLen, upLen, downLen;
	leftLen = rightLen = upLen = downLen = NO_PATH;
	Coord lefCoord(curr.m_col - 1, curr.m_row),
		rightCoord(curr.m_col + 1, curr.m_row),
		upCoord(curr.m_col, curr.m_row - 1),
		downCoord(curr.m_col, curr.m_row + 1);
	leftLen = find_shortest_path(board, helpBoard, lefCoord);
	rightLen = find_shortest_path(board, helpBoard, rightCoord);
	if(board.get_char(upCoord) == LADDER)
		upLen = find_shortest_path(board, helpBoard, upCoord);
	if (board.get_char(downCoord) != WALL)
		downLen = find_shortest_path(board, helpBoard, downCoord);
	
	int shortest = leftLen;
	if ((rightLen < shortest && rightLen != NO_PATH) || shortest == NO_PATH)
		shortest = rightLen;
	if ((upLen < shortest && upLen != NO_PATH) || shortest == NO_PATH)
		shortest = upLen;
	if ((downLen < shortest && downLen != NO_PATH) || shortest == NO_PATH)
		shortest = downLen;
	if (shortest != NO_PATH)
		shortest++;
	return shortest;
	//return shortest == NO_PATH ? NO_PATH : shortest + 1;
}