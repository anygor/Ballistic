#include "wall.h"

Wall::Wall() {
	wallTexture.loadFromFile("stone2_b.png");
	wall.setTexture(wallTexture);
	wall.setScale(0.05, 0.05);
}

void Wall::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 50; j++) {
			if (i == 0 || j == 0 || i == 99 || j == 49) {
				wall.setPosition(206.0f + ((float)i*10.0f), 206.0f + ((float)j*10.0f));
				window.draw(wall);
			}
		}
	}
}