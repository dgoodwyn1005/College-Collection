#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Pong", Style::Fullscreen);
	int p1_lives = 3;
	int p2_lives = 3;
	bool GAMEOVER = false;
	int winner = 0;

	// Create first player bat at the bottom center of the screen
	Bat bat1(1920 / 2, 1080 - 20);
	// Create second player bat at the top center of the screen
	Bat bat2(1920 / 2, 20);

	// Create a ball in the center
	Ball ball(1920 / 2, 1080 / 2);

	// Create a Text object called HUD
	Text hud;
	// Get the font
	Font font;
	font.loadFromFile("fonts/DS-DIGI.ttf");
	// Set the font to our retro-style
	hud.setFont(font);
	// Make it nice and big
	hud.setCharacterSize(75);
	// Choose a color
	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);
	//Another Text object for end of game
	Text gameover;
	gameover.setPosition((1920 / 2) - 600, 1080 / 2);
	gameover.setFont(font);
	gameover.setCharacterSize(125);
	gameover.setFillColor(Color::Red);
	// Here is our clock for timing everything
	Clock clock;

	while (window.isOpen())
	{
		
		//Handle the player input
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				// Quit the game when the window is closed
				window.close();
		}

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		while (!GAMEOVER)
		{
			// Handle the pressing and releasing of the arrow keys, for player 1 bat
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				bat1.moveLeft();
			}
			else
			{
				bat1.stopLeft();
			}

			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				bat1.moveRight();
			}
			else
			{
				bat1.stopRight();
			}

			// Handle the pressing and releasing of the A & D, for player 2 bat
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				bat2.moveLeft();
			}
			else
			{
				bat2.stopLeft();
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				bat2.moveRight();
			}
			else
			{
				bat2.stopRight();
			}

			//Update the bat, the ball and the HUD

		// Update the delta time
			Time dt = clock.restart();
			bat1.update(dt);
			bat2.update(dt);
			ball.update(dt);

			// Update the HUD text
			std::stringstream ss;
			ss << "Player 1 Lives:" << p1_lives << " \nPlayer 2 Lives:" << p2_lives;
			hud.setString(ss.str());

			// Handle ball hitting the bottom
			if (ball.getPosition().top > window.getSize().y)
			{
				// reverse the ball direction
				ball.reboundBottom();

				// Remove a life
				p1_lives--;
				// Check for zero lives
				if (p1_lives < 1) {
					// Player 2 Wins
					winner = 2;
					// Update the Winner text
					std::stringstream ww;
					ww << "The winner is Player " << winner << " !";
					gameover.setString(ww.str());
					GAMEOVER = true;
				}
			}

			// Handle ball hitting top
			if (ball.getPosition().top < 0)
			{
				ball.reboundBottom();

				// Remove a life
				p2_lives--;
				// Check for zero lives
				if (p2_lives < 1) {
					// Player 1 Wins
					winner = 1;
					// Update the Winner text
					std::stringstream ww;
					ww << "The winner is Player " << winner << " !!!";
					gameover.setString(ww.str());
					GAMEOVER = true;
				}
			}

			// Handle ball hitting sides
			if (ball.getPosition().left < 1 ||
				ball.getPosition().left + ball.getPosition().width > window.getSize().x - 1)
			{
				ball.reboundSides();
			}

			// Has the ball hit one of the bats
			if (ball.getPosition().intersects(bat1.getPosition()))
			{
				// Hit detected so reverse the ball
				ball.reboundBatOrTop();
			}

			if (ball.getPosition().intersects(bat2.getPosition()))
			{
				// Hit detected so reverse the ball
				ball.reboundBatOrTop();
			}

			//Draw the bat, the ball and the HUD

			window.clear();
			window.draw(hud);
			window.draw(bat1.getShape());
			window.draw(bat2.getShape());
			window.draw(ball.getShape());
			window.display();
		}
		
		//Game has ended
		window.clear();
		window.draw(hud);
		window.draw(gameover);
		window.draw(bat1.getShape());
		window.draw(bat2.getShape());
		window.draw(ball.getShape());
		window.display();
	}

	return 0;
}