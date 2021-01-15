#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
#include "Textures.h"

class Animation {
public:
	static Animation& instance();
	void update(float);
	sf::IntRect get_rect(ObjectType) const;

private:
	Animation();
	Animation(const Animation&) = default;
	Animation& operator=(const Animation&) = default;

	int m_totalTime,
		m_currentImage;
};