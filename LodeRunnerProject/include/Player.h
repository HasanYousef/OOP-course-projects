#pragma once

#include <iostream>
#include <MoveableObject.h>

class Player : public MoveableObject {
public:
	//---Constructors---------------------------------------------------
	Player() : m_position(), m_health(INIT_HEALTH), m_texture() {}
	Player(const sf::Vector2f& position, sf::Texture* texture) : m_position(position),
		m_texture(texture), m_health(INIT_HEALTH) {}
	//---functions--------------
	void Player_move(const Board&);
	void die();
	void set_health(int);
	//---get-functions----------
	int get_health() const;
	int get_score() const;
	int get_health() const;
	//---add-functions----------
	void add_health(int);
	void add_score(int);
private:
	int m_health;
	int m_score = 0;
	//---help-functions-------------------
	bool is_wall(const Board&, int, int);
	bool fall(const Board&, const sf::Vector2f)
};
