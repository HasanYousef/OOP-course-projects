#pragma once

#include "Player.h"
#include <SFML/Graphics.hpp>

//-------------------------------------------------
int Player::get_score() const {
	return m_score;
}

//-------------------------------------------------
//here we return the helth number of the Player
int Player::get_health()const {
	return m_health;
}

//-------------------------------------------------
//here we sub 1 from the helth of the player when 
//the player get damged from a enemy
void Player::die() {
	m_health = m_health - 1;
}

//-------------------------------------------------
void Player::set_health(int currHealth) {
	m_health = currHealth;
}

//-------------------------------------------------
void Player::add_health(int more_health) {
	m_health += more_health;
}

//-------------------------------------------------
void Player::add_score(int more_score) {
	m_score += more_score;
}

//-------------------------------------------------
void Player::Player_move(const Board& board) {
	auto player = creat();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (!is_wall(board, get_position().x - speed, get_position().y)) {
			sf::Vector2f move(-SPEED, 0);
			move(move);
			set_position(get_position().x - SPEED, get_position().y);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (!is_wall(board, get_position().x + speed, get_position().y)) {
			sf::Vector2f move(SPEED, 0);
			move(move);
			set_position(get_position().x + SPEED, get_position().y);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (is_ladder(board, get_position().x, get_position().y - speed)) {
			sf::Vector2f move(0, -SPEED);
			move(move);
			set_position(get_position().x, get_position().y - SPEED);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sf::Vector2f move(0, SPEED);
		while (fall(Board & board), get_position()) {
			move(move);
			set_position(get_position().x, get_position().y + SPEED);
		}
	}
}

//------------------------------------------------------------
//here we check if the elment that we want to move on it its
//valued or not (if its a WALL or not)
bool Player::is_wall(const Board& board int col, int row) {
	return (board.get_type(col, row) == WALL);
}

//------------------------------------------------------------
//this func check if the player on the top of the ladder
//returne false if not and true if its on last H 
bool Player::fall(const Board& board, const sf::Vector2f points) {
	return board.get_type(point) != LADDER &&
		board.get_type(sf::Vector2f(points.x, points.y + 1)) != WALL
		&& board.get_type(Coord(m_coord.m_col + el, m_coord.m_row)) != ROPE;
}








