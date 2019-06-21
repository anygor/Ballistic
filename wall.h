#pragma once
#include "SFML\Graphics.hpp"

class Wall {
public:
	Wall();
	void draw(sf::RenderWindow&);

private:
	sf::Sprite wall;
	sf::Texture wallTexture;
};