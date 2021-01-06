#pragma once

#include "Controller.h"

//-----------------structor-----------------
//in the Controller structor, the maps file will be open
//and it's stream will be stored in the map stream variable
Controller::Controller() : m_level(0), m_numOfLevels(0) {
	open_maps_stream();
}

//-----------------run-----------------
void Controller::run() {
	//start_menu();
	start_game();
}

//-----------------start_menu-----------------
void Controller::start_menu() {

}

//-----------------start_game-----------------
void Controller::start_game() {
	m_level = 1;
	while (m_level <= m_numOfLevels) {
		m_map.readFromStream(m_mapsStream);
		run_level();
		m_level++;
	}
}

//-----------------run_level-----------------
void Controller::run_level() {
}

//---------------------------------------------
void Controller::open_maps_stream() {
	// try to open file to read
	fs::path p = MAP_PATH;
	m_mapsStream(fs::absolute(p));
	// if file doesn't exist open the editor
	if (!m_mapsStream)
		initNewMap();
}
