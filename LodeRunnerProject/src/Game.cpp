#pragma once

#include "Game.h"

//-----------------start_game-----------------
void Game::start() {
	m_level = 1;
	while (m_level <= m_numOfLevels) {
		m_map.readFromStream(m_mapsStream);
		run_level();
		m_level++;
	}
}

//-----------------run_level-----------------
void Game::run_level() {
	while () {

	}
}