#include<SFML\Graphics.hpp>
#include "Ball.h"

#include "Object.h"
#include<iostream>
#include <vector>
#define HEIGHT 700
#define WIDTH 1480
#define FIRST_X 950+5
#define FIRST_Y 325
#define SECOND_X 980
#define SECOND_Y 310
#define THIRD_X 1010
#define THIRD_Y 295 
#define FOURTH_X 1040 
#define FOURTH_Y 280 
#define FIFTH_X 1070
#define FIFTH_Y 265 



int main()
{

	//rendering window object made
	sf::RenderWindow window;
	//create window with certain width and height and name 
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Roshan");
	Object o;
	o.addBall(sf::Vector2f(400, 350),"whiteball.png", true);
	o.addBall(sf::Vector2f(FIRST_X, FIRST_Y));
	o.addBall(sf::Vector2f(SECOND_X, SECOND_Y + 30));
	o.addBall(sf::Vector2f(SECOND_X, SECOND_Y));
	
	o.addBall(sf::Vector2f(THIRD_X, THIRD_Y));
	o.addBall(sf::Vector2f(THIRD_X, THIRD_Y + 30));
	o.addBall(sf::Vector2f(THIRD_X, THIRD_Y + 60));
	o.addBall(sf::Vector2f(FOURTH_X, FOURTH_Y));
	o.addBall(sf::Vector2f(FOURTH_X, FOURTH_Y + 30));
	o.addBall(sf::Vector2f(FOURTH_X, FOURTH_Y + 60));
	o.addBall(sf::Vector2f(FOURTH_X, FOURTH_Y + 90));
	o.addBall(sf::Vector2f(FIFTH_X, FIFTH_Y));
	o.addBall(sf::Vector2f(FIFTH_X, FIFTH_Y + 30));
	o.addBall(sf::Vector2f(FIFTH_X, FIFTH_Y + 60));
	o.addBall(sf::Vector2f(FIFTH_X, FIFTH_Y + 90));
	o.addBall(sf::Vector2f(FIFTH_X, FIFTH_Y + 120));

	o.makeHole(sf::Vector2f(30.0f, 30.0f), 35.0f);
	o.makeHole(sf::Vector2f(700.0f, 2.0f), 35.0f);
	o.makeHole(sf::Vector2f(700.0f, 660.0f), 35.0f);
	o.makeHole(sf::Vector2f(1370.0f, 20.0f), 35.0f);//top right
	o.makeHole(sf::Vector2f(1370.0f, 620.0f), 35.0f);
	o.makeHole(sf::Vector2f(32.0f, 620.0f), 35.0f);

	
	o.addBoard();
	float deltatime = 0;
	sf::Clock tim;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseButtonPressed:



				break;
			}

		}
		deltatime = tim.restart().asSeconds();
		o.update(deltatime, window);
		o.display(window);
		window.display();
		window.clear();
		tim.restart();
	}
	return 0;

}