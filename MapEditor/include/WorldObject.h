#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"

class WorldObject {
public:
	WorldObject() : {}
	WorldObject(ObjectType = ObjectType::Space, const sf::Texture& = nullptr);
	void draw(sf::RenderWindow&) const;
	bool handleClick(const sf::Vector2f&);

private:
	sf::Sprite create() const;

	ObjectType m_objectType = ObjectType::Space;
	sf::Vector2f m_position;
	sf::Texture& m_texture = nullptr;
};