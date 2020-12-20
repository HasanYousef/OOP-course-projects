#pragma once

#include "WorldObject.h"

WorldObject::WorldObject(ObjectType type = ObjectType::Space,
	sf::Texture &texture,
	const sf::Vector2f &position) :
	m_objectType(type), m_texture(texture), m_position(position) {}

void WorldObject::draw(sf::RenderWindow& window) const {
	window.draw(create());
}

WorldObject& WorldObject::operator=(const WorldObject& other) {
	m_objectType = other.m_objectType;
	m_texture = other.m_texture;
	m_position = other.m_position;
	return *this;
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
