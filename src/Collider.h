#pragma once
#ifndef DE553327_1C10_4B07_BEF8_8675936B26ED
	#define DE553327_1C10_4B07_BEF8_8675936B26ED
	#include <SFML/Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy)
	{
		body.move(dx, dy);
	}

	bool CheckCollision(Collider other, float push);
	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	};
	sf::Vector2f GetHalfSize()
	{
		return body.getSize() / 2.0f;
	};

private:
	sf::RectangleShape& body;
};

#endif /* DE553327_1C10_4B07_BEF8_8675936B26ED */
