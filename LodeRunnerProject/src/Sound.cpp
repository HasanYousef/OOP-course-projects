#pragma once 

#include "Sound.h"

Sound& Sound::instance() {
	static Sound inst;
	return inst;
}

sf::Music* Sound::getSound(SoundEffects sound) const {
	auto soundEffect =  m_sound[sound];
	soundEffect->setVolume(70);
	return soundEffect;
}

Sound::Sound() {
	//initing the textures object in the array member
	for (int i = 0; i < NUM_OF_SOUND; i++)
		m_sound[i] = new sf::Music();

	(*m_sound[SoundEffects::GamePlay]).openFromFile("gamePlay.oog");
	(*m_sound[SoundEffects::Die]).openFromFile("getHit.oog");
	(*m_sound[SoundEffects::Hit]).openFromFile("getCoin.oog");
}