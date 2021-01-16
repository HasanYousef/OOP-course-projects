#pragma once

#include "Animation.h"

Animation::Animation() : m_totalTime(0), m_currentImage(0) {}

Animation& Animation::instance() {
	static Animation inst;
	return inst;
}

void Animation::update(float deltaTime) {
	m_totalTime += deltaTime;

	if (m_totalTime >= ANIMATION_SWITCH_TIME) {
		m_totalTime -= ANIMATION_SWITCH_TIME;
		m_currentImage++;
		if (m_currentImage >= ANIMATION_IMAGE_COUNT)
			m_currentImage = 0;
	}
}

sf::IntRect Animation::get_rect(ObjectType object) const {
	sf::IntRect rec;
	rec.width = Textures::instance().get_texture(object)->getSize().x / ANIMATION_IMAGE_COUNT;
	rec.height = Textures::instance().get_texture(object)->getSize().y;;
	rec.left = m_currentImage * rec.width;
	return rec;
}