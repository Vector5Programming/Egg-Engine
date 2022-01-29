#include "Ball.h"
#include "Platform.h"
#include "Player.h"
#include "Player2.h"
#include <Platform/Platform.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include <string>
using namespace std;

static const float VIEW_HEIGHT = 512.0f;
bool restart;
// void ResizeView(const sf::RenderWindow& window, sf::View& view);

void fail();
void fail() {
	restart = true;
}

int main()
{

	{

		while (!restart)
		{

			int player1score = 0;
			int player2score = 0;
			cout << player1score;
			cout << player2score;
			sf::RenderWindow window(sf::VideoMode(VIEW_HEIGHT, VIEW_HEIGHT), "Egg Engine! v0.0.4a", sf::Style::Close | sf::Style::Titlebar);
			sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

			Player player(250.0f);
			Player2 player2(250.0f);

			Ball ball(150 + 1);

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
							restart = true;
							window.close();
							break;

							// case sf::Event::Resized:
							// ResizeView(window, view);
							// break

						default:
							break;
					};

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						// left key is pressed: move our character
					}

					if (event.type == sf::Event::Closed)
						window.close();
				}
				player.Update(deltaTime);
				player2.Update(deltaTime);
				ball.Update(deltaTime);

				platform3.GetCollider().CheckCollision(player.GetCollider(), 1.0f);
				platform4.GetCollider().CheckCollision(player.GetCollider(), 1.0f);
				platform3.GetCollider().CheckCollision(player2.GetCollider(), 1.0f);
				platform4.GetCollider().CheckCollision(player2.GetCollider(), 1.0f);
				if (platform3.GetCollider().CheckCollision(ball.GetCollider(), 1.0f))
					ball.up = true;
				if (platform4.GetCollider().CheckCollision(ball.GetCollider(), 1.0f))
					ball.up = false;
				if (platform2.GetCollider().CheckCollision(ball.GetCollider(), 1.0f))
				{
					player2score++;
					fail();
				}

				if (platform1.GetCollider().CheckCollision(ball.GetCollider(), 1.0f))
				{
					player1score++;
					fail();
				}

				if (player.GetCollider().CheckCollision(ball.GetCollider(), 1.0f))
					ball.right = true;
				if (player2.GetCollider().CheckCollision(ball.GetCollider(), 1.0f))
					ball.right = false;

				// view.setCenter(player.GetPosition());

				window.clear(sf::Color::Black);
				player.Draw(window);
				player2.Draw(window);
				ball.Draw(window);
				platform1.Draw(window);
				platform2.Draw(window);
				platform3.Draw(window);
				platform4.Draw(window);
				// ball.Draw(window);
				window.display();
			}
		}
	}

	return 0;
}