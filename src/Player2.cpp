#include "Player2.h"

Player2::Player2(float speed)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(25.0f, 100.0f));
	body.setOrigin(body.getSize() / 2.0f);

	body.setPosition(490.0f, 206.0f);
}

Player2::~Player2()
{
}

void Player2::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y += speed * deltaTime;
	}

	if (movement.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;

		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	body.move(movement);
}

void Player2::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}