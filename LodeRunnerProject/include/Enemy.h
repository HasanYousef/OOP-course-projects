#pragma once

#include <SFML/Graphics.hpp>
#include <MoveableObject.h>

class Enemy : public MoveableObject {
public:
	Enemy();
	Enemy(ObjectType, sf::Texture*,
		const sf::Vector2f&, int);
	int setIq(int);
	void move(const Map&);

private:
	int m_iq;
	//---move---functions-----
	void stupidMove(const Map&);
	void smartMove(const Map&);
	void normalMove(const Map&);
};