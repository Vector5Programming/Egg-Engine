#include "Ball.h"

Ball::Ball(float speed)
{
	this->speed = speed;

	body.setSize(sf::Vector2f(20.0f, 20.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setPosition(206.0, 206.0f);
}

Ball::~Ball()
{
}

void Ball::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	srand(time(0));



	if (right)
	{
		movement.x += speed * deltaTime;
	}
	else if (!right)
	{
		movement.x -= speed * deltaTime;
	};

	if (up)
	{
		movement.y += speed * deltaTime;
	} else 	if (!up)
	{
		movement.y -= speed * deltaTime;
	}

	body.move(movement);
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}