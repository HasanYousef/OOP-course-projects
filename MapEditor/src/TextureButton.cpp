#pragma once

#include "TextureButton.h"

//------------------------------------------------------
TextureButton::TextureButton(const sf::Texture* texture,
	const sf::Vector2f& position,
	ObjectType type) :
	m_texture(texture), 
	m_type(type) {
	m_position = position;
}

void TextureButton::draw(sf::RenderWindow& window) const {
	window.draw(create());

	auto result = sf::Sprite(*m_texture);
	result.setPosition(m_position);
	result.setOrigin(sf::Vector2f(result.getTexture()->getSize() / 2u));
	window.draw(result);
}

//------------------------------------------------------
//this func return the type of the botton(player,coin..)
ObjectType TextureButton::getType() const {
	return m_type;
}