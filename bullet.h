#pragma once
#include "SFML\Graphics.hpp"
#include "direction.h"
#include "cannon.h"
#include "wall.h"
#include <Windows.h>

class Cannon;

class Bullet {
public:
	Bullet();
	Bullet(float&, float&, float&, float&);
public:
	//void set_speed(float&);
	//void set_angle(float&);
	//void set_coords(float&, float&);
	void drawBullet(sf::RenderWindow&);
	void update(sf::RenderWindow&, Direction, Cannon&, Cannon&, Wall&, bool&,float time);

	//float get_speed();
	//float get_angle();
	//float get_posx(), get_posy();

	//float get_Xspeed();
	//float get_Yspeed();
private:
	float m_speed;
	float m_angle;
	float m_posx, m_posy;
	sf::Sprite bullet;
	sf::Texture bulletTexure;
};