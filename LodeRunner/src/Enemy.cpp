#pragma once

#include "Enemy.h"

//---get---enemy---indexes---------------------
Coord Enemy::get_coord() const
{
	return m_coord;
}

//---------------------------------------------
Coord Enemy::move(const Board& board, const Coord& pCoord)
{
	Coord leftCoord(m_coord.m_col + 1, m_coord.m_row),
		rightCoord(m_coord.m_col - 1, m_coord.m_row);

	if (pCoord.m_row == m_coord.m_row) {
		if (board.get_char(leftCoord) != WALL)
			return leftCoord;
		if (board.get_char(rightCoord) != WALL)
			return rightCoord;
	}
	if (board.get_char(m_coord) == LADDER) {
		if (pCoord.m_row < m_coord.m_row)
			return Coord(m_coord.m_col, m_coord.m_row - 1);
		return Coord(m_coord.m_col, m_coord.m_row + 1);
	}
	else {
		if (there_is_laddder(board, -1)) {
			m_coord = rightCoord;
			return rightCoord;
		}
		else {
			m_coord = leftCoord;
			return leftCoord;
		}
	}
	//if there is something wrong (should not be if the input is correct) return the same coord
	return m_coord;
}

bool Enemy::there_is_laddder(const Board& board, int dir) {
	Coord coord(m_coord);
	while (board.get_char(coord) != WALL) {
		if (board.get_char(coord) == LADDER || board.get_char(coord) == ROPE)
			return true;
		coord = Coord(coord.m_col + dir, coord.m_row);
	}
	return false;
}