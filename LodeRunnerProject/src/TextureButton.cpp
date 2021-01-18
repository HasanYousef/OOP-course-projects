#pragma once

#include "TextureButton.h"

TextureButton::TextureButton() :
	m_type(ObjectType::O_Space)
{}

//------------------------------------------------------
//constructor that take a texture to put a texture on the botton
TextureButton::TextureButton(const sf::Vector2f& position,
	ObjectType type) :
	m_type(type) {
	m_position = position;
}

//------------------------------------------------------
//this a copy constructor
void TextureButton::draw(sf::RenderWindow& window) const {
	window.draw(create());

	auto result = sf::Sprite(*(Textures::instance().get_texture(m_type)));
	result.setPosition({ m_position.x + 40, m_position.y + 8 });
	window.draw(result);
}

//------------------------------------------------------
//this func return the type of the botton(player,coin..)
ObjectType TextureButton::getType() const {
	return m_type;
}

void TextureButton::set_type(ObjectType type) {
	m_type = type;
}