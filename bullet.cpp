#include "bullet.h"
#include <cmath>
#include <iostream>

Bullet::Bullet() {}

Bullet::Bullet(float& speed, float& angle, float& x, float& y) {
	m_speed = speed;
	m_angle = angle;
	m_posx = x;
	m_posy = y;

	bulletTexure.loadFromFile("bullet_.png");
	bullet.setTexture(bulletTexure);
	bullet.setPosition(m_posx, m_posy);
	bullet.setScale(0.03, 0.04);
}

//void Bullet::set_speed(float& speed) {
//	m_speed = speed;
//}
//
//void Bullet::set_angle(float& angle) {
//	m_angle = angle;
//}
//
//void Bullet::set_coords(float& x, float& y) {
//	m_posx = x;
//	m_posy = y;
//}
//
//float Bullet::get_Xspeed() {            // mistake here
//	return m_speed * cos(m_angle);
//}
//
//float Bullet::get_Yspeed() {              // and here ofc
//	return m_speed * sin(m_angle);
//}
//
//float Bullet::get_speed() {
//	return m_speed;
//}
//
//float Bullet::get_angle() {
//	return m_angle;
//}
//
//float Bullet::get_posx() {
//	return m_posx;
//}
//
//float Bullet::get_posy() {
//	return m_posy;
//}

void Bullet::drawBullet(sf::RenderWindow& window) {
	window.draw(bullet);
}

void Bullet::update(sf::RenderWindow& window, Direction dir, Cannon& player1, Cannon& player2, Wall& wall, bool& struck, float t) {
	bool done = false, breaker = false, returner = false;
	float vx, vy;
	if (dir == right) {
		vx = (m_speed)* cos(m_angle), vy = -(m_speed)* sin(m_angle);
	}
	else {
		vx = -(m_speed)* cos(m_angle), vy = -(m_speed)* sin(m_angle);
	}
	bullet.setPosition(m_posx, m_posy);
	while (!done) {
			//while (m_posy > 210 && m_posy < 665  && m_posx  > 210  && m_posx < 185 + 1000) {
		std::cout << "X: " << m_posx << std::endl;
		std::cout << "Y: " << m_posy << std::endl;
		m_posx = m_posx + (vx)* t;
		std::cout << "X2: " << m_posx << std::endl;
		std::cout << "Y2: " << m_posy << std::endl;
		if ((m_posx >= 1100 && m_posy >= 630 && dir == right)||(dir == left && m_posx <= 290 && m_posy >= 630)) {   //player hit check(probitie)
			done = true;
			std::cout << "player win" << std::endl;
			Sleep(100);
			bullet.setPosition(m_posx, m_posy);
			sf::CircleShape explosion(80.0f, 80.0f);
			sf::Texture explosionTexture;
			explosionTexture.loadFromFile("expl.png");
			explosion.setTexture(&explosionTexture);
			explosion.setPosition(m_posx - 50, m_posy - 50);
			window.clear();
			drawBullet(window);
			player1.draw(window);
			player2.draw(window);
			wall.draw(window);
			window.draw(explosion);
			window.display();
			struck = false;
			returner = true;
			break;
			//return false;
		}
		if (m_posx <= 210) {
			m_posx = 210;
			done = true;
			breaker = true;
		}
		else if (m_posx >= 185 + 1000) {
			m_posx = 185 + 1000;
			done = true;
			breaker = true;
		} // walls checkout
		m_posy = m_posy + (vy)*t + 9.8*t*t;
		if (m_posy <= 210) {
			m_posy = 210; 
			done = true;
			breaker = true;
		}
		else if (m_posy >= 675) { 
			m_posy = 675; 
			done = true;
			breaker = true;
		}  // floor and ceiling checkout
		std::cout << "TIME(): " << t << std::endl;
		vy += 9.8*t;
		bullet.setPosition(m_posx, m_posy);
		window.clear();
		drawBullet(window);
		player1.draw(window);
		player2.draw(window);
		wall.draw(window);
		window.display();
		if (breaker) 
			break;
	}
	if (!returner)
		struck = true;
}