#pragma once

#include "WorldObject.h"
#include <SFML/Graphics.hpp>
#include "Textures.h"

//-------------------------------------------------
WorldObject::WorldObject() {
	m_position = sf::Vector2f({ 0,0 });
	m_objectType = O_Space;
}

//-------------------------------------------------
WorldObject::WorldObject(ObjectType type, 
	              const sf::Vector2f& position) :
	m_objectType(type), m_position(position) {}

//-------------------------------------------------
sf::Vector2f WorldObject::get_position() const {
	return m_position;
}

//-------------------------------------------------
void WorldObject::set_position(const sf::Vector2f& position) {
	m_position = position;
}

//-------------------------------------------------
void WorldObject::setType(ObjectType type) {
	m_objectType = type;
}

//-------------------------------------------------
//this func draw the object
void WorldObject::draw(sf::RenderWindow& window) const {
	window.draw(create());
}

//-------------------------------------------------
//we get the type of the object(player,enemy....)
ObjectType WorldObject::get_type() const {
	return m_objectType;
}

//-------------------------------------------------
//this operator = that let us copy another object
WorldObject& WorldObject::operator=(const WorldObject& other) {
	m_objectType = other.m_objectType;
	m_position = other.m_position;
	return *this;
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite WorldObject::create() const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		                 get_texture(m_objectType));
	result.setPosition(m_position);
	result.getPosition();
	return result;
}
