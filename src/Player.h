#ifndef A476290E_FA2F_4001_B8D7_AF7ABB2FA426
#define A476290E_FA2F_4001_B8D7_AF7ABB2FA426

#include "Animation.h"
#include <SFML/Graphics.hpp>

class Player{
	public:
	Player(sf::Texture* texture, sf::Vector2u imagecount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};

#endif /* A476290E_FA2F_4001_B8D7_AF7ABB2FA426 */
