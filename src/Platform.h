#pragma once
#ifndef B667B67D_3AAF_4456_922B_75A44350986E
#define B667B67D_3AAF_4456_922B_75A44350986E
#include <SFML/Graphics.hpp>
#include <Collider.h>

class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
};

#endif /* B667B67D_3AAF_4456_922B_75A44350986E */
