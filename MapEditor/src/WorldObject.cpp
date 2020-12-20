#pragma once

#include "WorldObject.h"

WorldObject::WorldObject(ObjectType type = ObjectType::Space,
	const sf::Texture &texture = nullptr) :
	m_objectType(type), m_texture(texture) {}


void WorldObject::draw(sf::RenderWindow& window) const {
	window.draw(create());
}

	// NO NEEEEEEEEED FOR THIS PROBABLY
bool WorldObject::handleClick(const sf::Vector2f& location)
{
	return create().getGlobalBounds().contains(location);
}

sf::Sprite WorldObject::create() const {
	auto result = sf::Sprite(m_texture);
	result.setPosition(m_position);
	return result;
}
