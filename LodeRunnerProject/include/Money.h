#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Money : StaticObject {
public:
	Money();
	Money(ObjectType, sf::Texture*,
		const sf::Vector2f&);
private:
	bool m_isTaken = false;
};