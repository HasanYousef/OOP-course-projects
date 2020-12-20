#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"

class WorldObject {
public:
	WorldObject(ObjectType, const sf::Texture&, const sf::Vector2f&);
	void draw(sf::RenderWindow&) const;
	bool handleClick(const sf::Vector2f&);

private:
	sf::Sprite create() const;

	ObjectType m_objectType = ObjectType::Space;
	sf::Vector2f m_position;
	const sf::Texture& m_texture;
};