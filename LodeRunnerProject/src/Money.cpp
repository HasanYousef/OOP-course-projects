#pragma once

#include "Money.h"

//---------------------------------------------
Money::Money() : m_isTaken(false) {}

//---------------------------------------------
Money::Money(ObjectType type, sf::Texture* t,
	const sf::Vector2f& position) :
	StaticObject(type, t, position),
	m_isTaken(false) {}

//---------------------------------------------
