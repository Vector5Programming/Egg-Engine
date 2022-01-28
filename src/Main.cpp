#include "Platform.h"
#include "Player.h"
#include <Platform/Platform.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

static const float VIEW_HEIGHT = 512.0f;
// void ResizeView(const sf::RenderWindow& window, sf::View& view);

int main()
{

	{
		sf::RenderWindow window(sf::VideoMode(512, 512), "Egg Engine! v0.0.4a", sf::Style::Close | sf::Style::Titlebar);
		sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

		Player player(250.0f);

		Platform platform1(nullptr, sf::Vector2f(10.0f, VIEW_HEIGHT), sf::Vector2f(0.0f, VIEW_HEIGHT / 2.0f));
		Platform platform2(nullptr, sf::Vector2f(10.0f, VIEW_HEIGHT), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT / 2.0f));
		Platform platform3(nullptr, sf::Vector2f(VIEW_HEIGHT, 10.0f), sf::Vector2f(VIEW_HEIGHT / 2.0f, 0.0F));
		Platform platform4(nullptr, sf::Vector2f(VIEW_HEIGHT, 10.0f), sf::Vector2f(VIEW_HEIGHT / 2.0f, VIEW_HEIGHT));

		float deltaTime = 0.0f;
		sf::Clock clock;

		while (window.isOpen())

		{
			deltaTime = clock.restart().asSeconds();

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
					case sf::Event::Closed:
						window.close();
						break;

						// case sf::Event::Resized:
						// ResizeView(window, view);
						// break;

					default:
						break;
				}

				if (event.type == sf::Event::Closed)
					window.close();
			}
			player.Update(deltaTime);

			platform1.GetCollider().CheckCollision(player.GetCollider(), 1.0f);
			platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);
			platform3.GetCollider().CheckCollision(player.GetCollider(), 1.0f);
			platform4.GetCollider().CheckCollision(player.GetCollider(), 1.0f);

			// view.setCenter(player.GetPosition());

			window.clear(sf::Color::Black);
			player.Draw(window);
			platform1.Draw(window);
			platform2.Draw(window);
			platform3.Draw(window);
			platform4.Draw(window);
			window.display();
		}
	}

	return 0;
}