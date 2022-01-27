#include <SFML/Graphics.hpp>
#include <Platform/Platform.hpp>
#include "Animation.h"
#include <iostream>

int main()
{{
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("texture.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture, sf::Vector2u(3,9), 0.3f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	sf::Vector2u texturesize = playerTexture.getSize();
	texturesize.x /= 9;
	texturesize.y /= 9;

	player.setTextureRect(sf::IntRect(texturesize.x * 2, texturesize.y * 2, texturesize.x , texturesize.y));

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);

		window.clear();
		window.draw(player);
		window.display();
	}}

	return 0;
}