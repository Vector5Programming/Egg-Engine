#ifndef A3DB497E_D227_4BD5_8CC0_58A14D9DB383
#define A3DB497E_D227_4BD5_8CC0_58A14D9DB383
#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imagecount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime, bool faceRight);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imagecount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};


#endif /* A3DB497E_D227_4BD5_8CC0_58A14D9DB383 */
