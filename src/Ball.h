#ifndef C35977E8_FF91_4F11_B91E_86983DC7C577
#define C35977E8_FF91_4F11_B91E_86983DC7C577
#include "Collider.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <time.h>

class Ball
{

public:
	Ball(float speed);
	~Ball();

	void Update(float deltaTime);
	bool right = false;
	bool up = true;
	void Draw(sf::RenderWindow& window);


	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	};

	Collider GetCollider()
	{
		return Collider(body);
	}

	sf::RectangleShape body;

private:
	unsigned int row;
	float speed;
	bool faceRight;
};

#endif /* C35977E8_FF91_4F11_B91E_86983DC7C577 */
