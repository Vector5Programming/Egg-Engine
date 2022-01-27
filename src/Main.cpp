#include <SFML/Graphics.hpp>
#include <Platform/Platform.hpp>
#include "Player.h"
#include <iostream>

int main()
{{
	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!", sf::Style::Close | sf::Style::Titlebar);
	sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(512.f, 512.f));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("texture.png");

	Player player(&playerTexture, sf::Vector2u(3,9), 0.3f, 100.0f);

	float deltaTime = 0.0f;
	sf::Clock clock;

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
		player.Update(deltaTime);

		window.clear();
		player.Draw(window);
		window.display();
	}}

	return 0;
}