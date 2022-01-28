#ifndef A476290E_FA2F_4001_B8D7_AF7ABB2FA426
#define A476290E_FA2F_4001_B8D7_AF7ABB2FA426

#include "Collider.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	};

	Collider GetCollider()
	{
		return Collider(body);
	}

private:
	sf::RectangleShape body;
	unsigned int row;
	float speed;
	bool faceRight;
};

#endif /* A476290E_FA2F_4001_B8D7_AF7ABB2FA426 */
