#pragma once
#include "direction.h"
#include "bullet.h"
#include <SFML\Graphics.hpp>
#include "wall.h"

class Cannon {
public:
	Cannon();
	Cannon(float, float, Direction);
public:
	//float get_posx(), get_posy();
	//Direction get_direction();
	//Bullet get_bullet();

	//void set_posx(float), set_posy(float), set_direction(Direction);

	//float get_bullet_Xspeed();
	//float get_bullet_Yspeed();

	void draw(sf::RenderWindow&);
	bool update(sf::RenderWindow&, Cannon&, Cannon&, Wall&,float time);

private:
	float m_posx, m_posy;
	Direction m_direction;
	//Bullet m_bullet;
	sf::Sprite player;
	sf::Texture playertexture;
};