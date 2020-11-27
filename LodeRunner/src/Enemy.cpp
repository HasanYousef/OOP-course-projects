#pragma once

#include "Enemy.h"

//---get---enemy---indexes---------------------
Coord Enemy::get_coord() const
{
	return m_coord;
}

//---------------------------------------------
//this will return the coord that the enemy should move to
//according to the hard coded AI path finder (to reach the player)
Coord Enemy::move(const Board& board, const Coord& pCoord)
{
	Coord leftCoord(m_coord.m_col - 1, m_coord.m_row),
		rightCoord(m_coord.m_col + 1, m_coord.m_row),
		upCoord(m_coord.m_col, m_coord.m_row - 1),
		downCoord(m_coord.m_col, m_coord.m_row + 1);
	//if the player is in the same coord as the enemy
	if (pCoord == m_coord)
		return m_coord;
	//if the player and the enemy are in the same row
	if (pCoord.m_row == m_coord.m_row) {
		//go left if he can go left and if the player is in the left
		if (board.get_char(leftCoord) != WALL
			&& pCoord.m_col < m_coord.m_col
			&& (can_go_side(board, +1) || board.get_char(m_coord) == ROPE)) {
			m_coord = board.get_ground(leftCoord);
			return m_coord;
		}
		//go right if he can go right and if the player is in the right
		if (board.get_char(rightCoord) != WALL
			&& pCoord.m_col > m_coord.m_col
			&& (can_go_side(board, -1) || board.get_char(m_coord) == ROPE)) {
			m_coord = board.get_ground(rightCoord);
			return m_coord;
		}
	}
	//if the enemy is on a rope and the playe is in the same row go to his dir
	if (board.get_char(m_coord) == ROPE
		&& pCoord.m_row > m_coord.m_row) {
		m_coord = board.get_ground(Coord(m_coord.m_col, m_coord.m_row + 1));
		return m_coord;
	}
	//if the enemy is on a ladder go up or down
	if (board.get_char(m_coord) == LADDER) {
		//go up
		if (pCoord.m_row < m_coord.m_row && board.get_char(upCoord) == LADDER) {
			m_coord = upCoord;
			return m_coord;
		}
		//go down
		else if (board.get_char(downCoord) == LADDER) {
			m_coord = Coord(m_coord.m_col, m_coord.m_row + 1);
			return m_coord;
		}
	}
	//if the player isn't in the same row, find the closest ladder or jump-down or rope
	//and go to it's dir
	else {
		int leftLadderDis = ladder_dis(board, -1);
		int rightLadderDis = ladder_dis(board, +1);
		//if thee is no ladder or rope in both sides stay in the same coord
		if (leftLadderDis == rightLadderDis && leftLadderDis == -1) {
			return m_coord;
		}
		//left is closer
		if (rightLadderDis == -1 || (leftLadderDis < rightLadderDis && leftLadderDis != -1)) {
			m_coord = board.get_ground(leftCoord);
			return m_coord;
		}
		//right is closer
		else {
			m_coord = board.get_ground(rightCoord);
			return m_coord;
		}
	}
	//if there is something wrong (should not be if the input is correct) return the same coord
	return m_coord;
}

//returns the distance of the enemy to the closest jump-down or ladder or rope
//in the given side and board (dir = -1 means left, dir = +1 means right)
//it will return -1 if there is nothing found
int Enemy::ladder_dis(const Board& board, int dir) {
	Coord coord(m_coord);
	int counter = 0;
	//keep searching until reaching a wall
	while (board.get_char(coord) != WALL) {
		//return the counter if found a jump-down or ladder or rope
		if (board.get_char(coord) == LADDER || board.get_char(coord) == ROPE
			|| board.get_char(Coord(coord.m_col, coord.m_row + 1)) == EMPTY)
			return counter;
		//preparing to check the next coord
		coord = Coord(coord.m_col + dir, coord.m_row);
		counter++;
	}
	//if there is no ladder or rope or jump-down found in this side
	return -1;
}

//checks if the enemy can go to the given side (dir = -1 means left, dir = +1 means right)
//it will check if there is floor in the given side
bool Enemy::can_go_side(const Board& b, int dir) {
	char leftCorner = b.get_char(Coord(m_coord.m_col - 1, m_coord.m_row + 1)),
		rightCorner = b.get_char(Coord(m_coord.m_col + 1, m_coord.m_row + 1));
	if (b.get_char(Coord(m_coord.m_col + dir, m_coord.m_row)) == ROPE)
		return true;
	if (dir > 0) {
		return (leftCorner == WALL);
	}
	return rightCorner == WALL;
}