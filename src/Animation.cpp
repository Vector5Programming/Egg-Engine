#include "Animation.h"

Animation::Animation(sf::Texture * texture, sf::Vector2u imagecount, float switchTime)
{
	this->imagecount = imagecount;
	this->switchTime = switchTime;
	totalTime = 0;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imagecount.x);
	uvRect.height = texture->getSize().y / float(imagecount.y);
}

Animation::~Animation()
{

}

void Animation::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imagecount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}