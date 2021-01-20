#pragma once

#include <SFML/Audio.hpp>
#include <vector>

#include "macros.h"

class Sounds {
public:
	static Sounds& instance();
	sf::Sound* getSound(SoundType);

private:
	Sounds();
	sf::Sound* m_sounds[NUM_OF_SOUNDS];
	sf::SoundBuffer* m_buffers[NUM_OF_SOUNDS];
};