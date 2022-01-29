#ifndef EFDE2280_C08E_414A_932E_88D835677786
#define EFDE2280_C08E_414A_932E_88D835677786
#include "Collider.h"
#include <SFML/Graphics.hpp>

class Player2
{
public:
	Player2(float speed);
	~Player2();

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

#endif /* EFDE2280_C08E_414A_932E_88D835677786 */
