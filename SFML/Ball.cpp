#include "Ball.h"
#include <iostream>
#include <SFML\System\Time.hpp>


Ball::Ball()
{
}

Ball::Ball(float r, sf::Texture texture, const char * file_path, sf::Vector2f pos)
{
	circle_texture = texture;
	file = file_path;
	radius = r;
	position = pos;
	circle_texture.loadFromFile(file);
	c.setTexture(circle_texture);
	c.setPosition(position);
	c.setScale(sf::Vector2f(0.13f, 0.13f));
	this->white_ball = white_ball;
	velocity.x = 0;
	velocity.y = 0;
	
	
}
void Ball::draw(sf::RenderWindow & window)
{
	window.draw(c);
}



bool Ball::collission(Ball &b)
{
	
	
	sf::Vector2f distance = sf::Vector2f(b.position.x - position.x, b.position.y - position.y);
	float d = sqrt(pow(distance.x, 2) + pow(distance.y, 2));
	if (d < 30.0f)
	{
		if (b.velocity.x * velocity.x > 0)
		{
			float d = b.velocity.x;
			float e = velocity.x;
			b.velocity.x = b.velocity.x + e;
			velocity.x = velocity.x - d;
		}
		else if (b.velocity.x * velocity.x < 0)
		{
			float a;
			a = b.velocity.x;
			b.velocity.x = velocity.x;
			velocity.x = a;

		}
		else if(b.velocity.x == 0)
		{
			b.velocity.x = velocity.x;
			velocity.x = 0;
			
		}
		if (b.velocity.y * velocity.y > 0)
		{
			float d = b.velocity.y;
			float e = velocity.y;
			b.velocity.y = b.velocity.y + e;
			velocity.y= velocity.y - d;
		}
		else if (b.velocity.y * velocity.y < 0)
		{
			float a;
			a = b.velocity.y;
			b.velocity.y = velocity.y;
			velocity.y = a;

		}
		else if (b.velocity.y== 0)
		{
			b.velocity.y = velocity.y;
			velocity.y= 0;

		}
		
		/*b.velocity = velocity + b.velocity;
		velocity = velocity - b.velocity;*/
		return true;
	}
	
}
void Ball::change_velocity()
{
	sf::Clock clock;
	float x = clock.getElapsedTime().asSeconds();
	std::cout << "TIME" << x << std::endl;
	//velocity.x = velocity.x - 2 * clock.getElapsedTime().asSeconds();
	if (velocity.x > 0)
	{
		velocity.x = velocity.x - 15 * clock.getElapsedTime().asSeconds();
		if (velocity.x < 0)
		{
			velocity.x = 0;
			std::cout << "VELOCITY.X at x>0" << velocity.x << std::endl;
			clock.restart();
		}
	}
	if (velocity.y > 0)
	{
		velocity.y = velocity.y - 15 * clock.getElapsedTime().asSeconds();
		if (velocity.y < 0)
		{
			velocity.y = 0;
			std::cout << "VELOCITY.y at x>0" << velocity.y << std::endl;
			clock.restart();
		}
	}
	if (velocity.x < 0)
	{
		velocity.x = velocity.x +15 * clock.getElapsedTime().asSeconds();
		if (velocity.x > 0)
		{
			velocity.x = 0;
			std::cout << "VELOCITY.X at x<0" << velocity.x << std::endl;
			clock.restart();
		}
	}
	if (velocity.y < 0)
	{
		velocity.y = velocity.y + 15 * clock.getElapsedTime().asSeconds();
		if (velocity.y > 0)
		{
			velocity.y = 0;
			std::cout << "VELOCITY.y at x<0" << velocity.y << std::endl;
			clock.restart();
		}
	}
}
void Ball::transfer_momentum(Ball & b)
{
	if (collission(b))
	{
		if (b.velocity.x * velocity.x > 0)
		{
			float d = b.velocity.x;
			float e = velocity.x;
			b.velocity.x = b.velocity.x + e;
			velocity.x = velocity.x - d;
		}
		else if (b.velocity.x * velocity.x < 0)
		{
			float a;
			a = b.velocity.x ;
			b.velocity.x = velocity.x;
			velocity.x = a;

		}
	}

}


void Ball::update()
{
	sf::Time t;
	
	sf::Clock clock;
	
	if (white_ball)
	{//key events for movement
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			velocity.y = -2.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			velocity.y = 2.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			velocity.x = -2.0f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			velocity.x = 2.0f;
		}
	}
	change_velocity();
	//board_and_ball collission
	if (position.x > 1335.0f)
	{
		velocity.x = -velocity.x;
		std::cout << position.x << std::endl;
	}
	else if (position.y > 585.0f)
	{
		velocity.y = -velocity.y;
	}
	else if (position.y < 95.0f)
	{
		velocity.y = -velocity.y;
	}
	else if (position.x < 103.0f)
	{
		velocity.x = -velocity.x;
	}
	

	
	position = position + (velocity);
	c.setPosition(position);
	

}





Ball::~Ball()
{
}
