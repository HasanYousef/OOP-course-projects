#pragma once

#include "Player.h"

Coord Player::get_coord() {
	return m_coord;
}

//------------------------------------------------------------
//here we do the Player Movement we take the board class,
//we read from the user a input and we check if the input is 
//a arrows if no we do nothing if yes we check if the elment
//that we have to move on it its valued or not if yes we reset
//the coordinates of the player and return the new once
//if its not valied we do nothing
Coord Player::move(const Board& board)
{
	int row = m_coord.m_row,
		col = m_coord.m_col;
	int read_buff = _getch();

	switch (_getch())
	{
	case KB_UP://if we want to move up (Ladder case)
		if (board.get_char(Coord(col, row - 1)) == LADDER)
		{
			m_coord.m_row = m_coord.m_row - 1;//we reset the points
			m_coord = board.get_ground(m_coord);//get into the ground if its needs
		}
		return m_coord;//return the new points of the player
	case KB_DOWN://if we want to move down
		if (!is_wall(m_coord.m_col,m_coord.m_row + 1,board))
		{
			m_coord.m_row = m_coord.m_row + 1;//we reset the points
			m_coord = board.get_ground(m_coord);//get into the ground if its needs
		}
		return m_coord;//return the new points of the player
	case KB_RIGHT://if we want to move right
		if (!is_wall(m_coord.m_col + 1, m_coord.m_row , board))
		{
			if (fall_from_ladder(board, 1)) {//if we on ladder we cant fall
				return m_coord;
			}
			m_coord.m_col = m_coord.m_col + 1;//we reset the points
			m_coord = board.get_ground(m_coord);//get into the ground if its needs
		}
		return m_coord;//return the new points of the player
	case KB_LEFT://if we want to move left
		if (!is_wall(m_coord.m_col - 1, m_coord.m_row, board))
		{
			if (fall_from_ladder(board, -1)) {//if we on ladder we cant fall
				return m_coord;
			}
			m_coord.m_col = m_coord.m_col - 1;//we reset the points
			m_coord = board.get_ground(m_coord);//get into the ground if its needs
		}
		return m_coord;//return the new points of the player
	default://if its a unvalued inpute
		return m_coord;//we return the same points
	}
}

//------------------------------------------------------------
//here we check if the elment that we want to move on it its
//valued or not (if its a WALL or not)
bool Player::is_wall(int col, int row, const Board& board)
{
	return (board.get_char(Coord(col, row)) == WALL);
}

//------------------------------------------------------------
//here we return the helth number of the Player
int Player::get_health()const {
	return m_health;
}

//------------------------------------------------------------
//here we sub 1 from the helth of the player when the player
//get damged from a enemy
void Player::die() {
	m_health = m_health - 1;
}

//------------------------------------------------------------
//this func check if the player on the top of the ladder
//returne false if not and true if its on last H 
bool Player::fall_from_ladder(const Board& board, int el) {
	return board.get_char(m_coord) == PLAYER_ON_LADDER &&
		board.get_char(Coord(m_coord.m_col + el, m_coord.m_row + 1)) != WALL
		&& board.get_char(Coord(m_coord.m_col + el, m_coord.m_row)) != ROPE;
}

void Player::set_health(int currHealth) {
	m_health = currHealth;
}