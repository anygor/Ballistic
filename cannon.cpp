#include "cannon.h"
#include <iostream>

Cannon::Cannon(){}

Cannon::Cannon(float posx, float posy, Direction dir) {
	m_posx = posx;
	m_posy = posy;
	m_direction = dir;
	if (dir == right) {
		playertexture.loadFromFile("player1_.png");
	}
	else playertexture.loadFromFile("player2_.png");
	player.setTexture(playertexture);
	player.setPosition(posx, posy);
	std::cout<<playertexture.getSize().x<<std::endl;
	std::cout << playertexture.getSize().y<<std::endl;
	player.setScale(0.10, 0.10);
}

//void Cannon::set_posx(float posx) {
//	m_posx = posx;
//}
//
//void Cannon::set_posy(float posy) {
//	m_posy = posy;
//}
//
//void Cannon::set_direction(Direction dir) {
//	m_direction = dir;
//}
//
//float Cannon::get_posx() {
//	return m_posx;
//}
//
//float Cannon::get_posy() {
//	return m_posy;
//}
//
//Direction Cannon::get_direction() {
//	return m_direction;
//}
////
////Bullet Cannon::get_bullet() {
////	return m_bullet;
////}
////
////float Cannon::get_bullet_Xspeed() {
////	return m_bullet.get_Xspeed();
////}
////
////float Cannon::get_bullet_Yspeed() {
////	return m_bullet.get_Yspeed();
////}

void Cannon::draw(sf::RenderWindow& window) {
	window.draw(player);
}

bool Cannon::update(sf::RenderWindow& window, Cannon& player1, Cannon& player2, Wall& wall, float time) {
	float px, py, speed, angle; //     player1 bullet input variables
	if (m_direction == right)
		px = 300.0f;         //     player1 bullet starting point
	else px = 95.0f + 1000;
	py = 640.0f;      
	std::cout << "Type in initial speed (1-150 m/s)" << std::endl;
	std::cin >> speed;
	//speed = 91;
	std::cout << "Type in firing angle (rad)" << std::endl;
	std::cin >> angle;
	//angle = 0.785;

	Bullet bullet(speed, angle, px, py); //    real object bullet, not a sprite


	//std::cout << "TIME: " << t << std::endl;

	bool struck = false;

	bullet.update(window, m_direction, player1, player2, wall, struck, time);
	
	return struck;

}