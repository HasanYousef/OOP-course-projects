#pragma once

#include <SFML/Audio.hpp>
#include <vector>

#include "macros.h"

class Sound {
public:
	static Sound& instance();
	sf::Music* getSound(SoundEffects) const;

private:
	Sound();
	sf::Music* m_sound[NUM_OF_SOUND];
};