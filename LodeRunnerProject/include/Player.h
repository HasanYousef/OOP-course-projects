#pragma once

#include <iostream>
#include <MoveableObject.h>

class Player : public MoveableObject {
public:
	Player() : {}
	Player(const sf::Vector2f& position, sf::Texture* texture) : m_position(position),
		m_texture(texture), m_health(INIT_HEALTH) {}
	void move(const Board&);
	int get_health() const;
	void die();
	void set_health(int);
private:
	int m_health;
	//---help-functions-------------------
	bool is_wall(int, int, const Board&);
	bool fall_from_ladder(const Board& board, int el);
};
