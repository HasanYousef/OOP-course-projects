#pragma once

#include "TextureButton.h"

//------------------------------------------------------
TextureButton::TextureButton(const sf::Texture& texture, const sf::Vector2f& size, ObjectType type) {
	m_type = type;
	m_button.setSize(size);
	m_button.setTexture(&texture);
}

//------------------------------------------------------
//this func return the type of the botton(player,coin..)
ObjectType TextureButton::getType() const {
	return m_type;
}
