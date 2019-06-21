#include "gameWindow.h"
#include "cannon.h"
#include "wall.h"
#include <iostream>
#include <fstream>
#include <cstring>

GameWindow::GameWindow() {
	sf::RenderWindow window(sf::VideoMode(1600, 900), "That's the Spirit!");

	Cannon player1(225.0, 642.0, right);
	Cannon player2(105.0 + 1000, 642.0, left);

	Wall wall;
	bool isGameActive = true, p1w = false, p2w = false;


	sf::Font font;//шрифт 
	font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	sf::Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)

	sf::Clock clock;
	float time = 0.0;
	clock.restart();

	while (window.isOpen()) {
		while (time == 0) {
			time = clock.getElapsedTime().asMicroseconds();
			time /= 60;
		}
		clock.restart();
		while (isGameActive) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}
			window.clear();
			wall.draw(window); 
			player1.draw(window);
			player2.draw(window);
			text.setString("Player 1 turn: ");
			text.setPosition(300.0, 300.0);
			window.draw(text);
			window.display();
			// std::cout << "Player 1 turn: " << std::endl;
			isGameActive = player1.update(window, player1, player2, wall, time);
			if (isGameActive) {
				window.clear();
				wall.draw(window);
				player1.draw(window);
				player2.draw(window);
				text.setString("Player 2 turn: ");
				text.setPosition(300.0, 300.0);
				window.draw(text);
				window.display();
				isGameActive = player2.update(window, player1, player2, wall, time);
				if (!isGameActive)p2w = true;
			}
			else p1w = true;
		}
		if (p1w) {
			Sleep(1500);
			text.setString("Player 1 wins");
			text.setPosition(300.0, 300.0);
			window.draw(text);
			window.display();
			Sleep(1500);
			window.close();
		}
		else if (p2w) {

			Sleep(1500);
			text.setString("Player 2 wins");
			text.setPosition(300.0, 300.0);
			window.draw(text);
			window.display();
			Sleep(1500);
			window.close();
		}
	}
}