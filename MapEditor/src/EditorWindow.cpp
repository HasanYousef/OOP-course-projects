#pragma once

#include "EditorWindow.h"

EditorWindow::EditorWindow() :
	m_window(sf::VideoMode(800, 800), "Map Editor") {}

void EditorWindow::run() {
	while (m_window.isOpen()) {
		m_window.clear();
		m_board.draw(m_window);
		m_window.display();

		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				m_window.close();
				break;

			}
		}
	}
}