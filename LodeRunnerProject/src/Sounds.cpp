#pragma once 

#include "Sounds.h"

Sounds& Sounds::instance() {
	static Sounds inst;
	return inst;
}

sf::Sound* Sounds::getSound(SoundType sound) {
	return m_sounds[sound];
}

Sounds::Sounds() {
	//initing the textures object in the array member
	for (int i = 0; i < NUM_OF_SOUNDS; i++) {
		m_sounds[i] = new sf::Sound;
		m_buffers[i] = new sf::SoundBuffer;
	}

	(*m_buffers[SoundType::Theme]).loadFromFile("theme.ogg");
	(*m_sounds[SoundType::Theme]).setBuffer(*m_buffers[SoundType::Theme]);

	(*m_buffers[SoundType::GetHit]).loadFromFile("getHit.ogg");
	(*m_sounds[SoundType::GetHit]).setBuffer(*m_buffers[SoundType::GetHit]);

	(*m_buffers[SoundType::GetCoin]).loadFromFile("getCoin.ogg");
	(*m_sounds[SoundType::GetCoin]).setBuffer(*m_buffers[SoundType::GetCoin]);
}
