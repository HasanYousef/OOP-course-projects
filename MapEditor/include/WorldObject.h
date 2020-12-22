#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"

class WorldObject {
public:
	WorldObject(ObjectType, sf::Texture*, const sf::Vector2f&);
	//----------------------------------------------
	void draw(sf::RenderWindow&) const;
	bool handleClick(const sf::Vector2f&);
	WorldObject& operator=(const WorldObject&);
	ObjectType getType() const;

private:
	sf::Sprite create() const;

	ObjectType m_objectType = ObjectType::Space;
	sf::Vector2f m_position;
	sf::Texture* m_texture;
};
