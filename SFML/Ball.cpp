#include "Ball.h"
#include <iostream>
#include <SFML\System\Time.hpp>
#include <iostream>
sf::Texture Ball::circle_texture;

Ball::Ball()
{
}

Ball::Ball(float r, const char * file_path, sf::Vector2f pos ,bool white)
{
	ball_exist = true;
	file = file_path;
	radius = r;
	white_ball = white;
	position = pos;
	ballCenter = vec(position) +radius;
	circle_texture.loadFromFile(file);
	c.setTexture(circle_texture);
	c.setPosition(sf::Vector2f(position.x ,pos.y));
	c.setScale(sf::Vector2f(0.13f, 0.13f));
	velocity = sf::Vector2f(0.0f, 0.0f);
	
	
	
	balls.push_back(*this);
	id = balls.size();
}



bool Ball::collission(Ball &b)
{
	float p = sqrt(((position.x - b.position.x)*(position.x - b.position.x)) + ((position.y - b.position.y)*(position.y - b.position.y)));
	if (p <= 28)
	{
		return true;
	}
	else
		return false;
}

void Ball::transfer_momentum(Ball & b)
{
	float fDistance = sqrtf((position.x - b.position.x)*(position.x - b.position.x) + (position.y - b.position.y)*(position.y - b.position.y));

	float nx = (position.x - b.position.x) / fDistance;
	float ny = (position.y - b.position.y) / fDistance;


	float tx = -ny;
	float ty = nx;

	float dpTan1 = b.velocity.x * tx + b.velocity.y * ty;
	float dpTan2 = velocity.x * tx + velocity.y * ty;

	float dpNorm1 = b.velocity.x * nx + b.velocity.y* ny;
	float dpNorm2 = velocity.x * nx + velocity.y * ny;

	float m1 = dpNorm2;
	float m2 = dpNorm1;

	b.velocity.x = tx * dpTan1 + nx * m1;
	b.velocity.y = ty * dpTan1 + ny * m1;
	velocity.x = tx * dpTan2 + nx * m2;
	velocity.y = ty * dpTan2 + ny * m2;
	

}
void  Ball::add_pos()
{
	hole_pos(vec(80.0f,73.0f));
	hole_pos(vec(80.0f, 629.0f));
	hole_pos(vec(1384.0f, 73.0f));
	hole_pos(vec(1384.0f, 629.0f));
	hole_pos(vec(735.0f, 50.0f));
	hole_pos(vec(735.0f, 657.0f));
}
void Ball::hole_pos(vec d)
{
	pos.push_back(d);
}

void Ball::update(float deltatime ,sf::RenderWindow &window)
{
	//change_velocity();
//	sf:: time;
	


	
	if (white_ball)
	{//key events for movement

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			velocity.y = -0.5f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			velocity.y = 0.5f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			velocity.x = -0.5f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			velocity.x = 0.5f;
		}
		
		//std::cout << velocity.x << "  " << velocity.y << std::endl;
		if (sf::Event::MouseButtonPressed)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i po = sf::Mouse::getPosition(window);

				std::cout << po.x << "    " << po.y << std::endl;

				sf::Vertex line[]
				{
					sf::Vertex(sf::Vector2f(position.x + 30 , position.y + 30)),
					sf::Vertex(sf::Vector2f(po.x + 30, po.y + 30))
				};
				window.draw(line, 5, sf::Lines);
			}


		}
		

		
	}
	//board_and_ball collission
	if (position.x < 20)
	{
		velocity.y = -velocity.y;
	}
	else if (position.y < 23)
	{
		velocity.x = -velocity.x;
	}
	else if (position.x > 1442)
	{
		velocity.y = -velocity.y;
	}
	else if (position.y >688 )
	{
		velocity.x = -velocity.x;
	}
	if (position.y < 95.0f)
	{
		if ((position.x > 130.0f && position.x < 697.0f) || (position.x > 760.0f && position.x < 1315.0f))
			velocity.y = -velocity.y;
		else if (position.x )
			velocity.y = velocity.y;

		else
		{
			ball_exist = false;
		}
	}
	else if (position.y > 585.0f)
	{
		if ((position.x >155.0f && position.x <697.0f) || (position.x >744.0f && position.x <1315.0f))
			velocity.y = -velocity.y;
		else
		{
			ball_exist = false;
		}
	}
	else if (position.x > 1330.0f)
	{
		if ((position.y > 130.0f &&position.y < 577.0f))
			velocity.x = -velocity.x;

		else
		{
			ball_exist = false;
		}
	}
	else if (position.x < 105.0f)
	{
		if ((position.y > 120.0f &&position.y < 577.0f))
			velocity.x = -velocity.x;
		else
		{
			ball_exist = false;
		}
	}
	
	/*if ((position.x >155.0f && position.x >697.0f) || (position.x >776.0f && position.x >1317.0f))
			{
				velocity.x = -velocity.x;
				//std::cout << position.x << std::endl;
			}
			else if (position.y > 585.0f&&position.x>155&&position.x<1318)
			{
				velocity.y = -velocity.y;
			}
		 
			/*else if (position.x <=105.0f&&position.y>=138)
			{
				velocity.x = -velocity.x;
			}*/
		

	
		//change_velocity();
		
		accleration.x = -25.0f*velocity.x;
		accleration.y = -025.0f *velocity.y;

		velocity.x += accleration.x*deltatime;
		velocity.y += accleration.y*deltatime;
		//position.x += velocity.x*deltatime;
		//position.y += velocity .y*deltatime;
		position = position + vec(velocity);
		c.setPosition(sf::Vector2f(position.x , position.y));
		//std::cout << velocity.length() << std::endl;
		if (velocity.length()< 0.10f)
		{
			velocity.x = 0;
			velocity.y = 0;

		}
}

void Ball::draw(sf::RenderWindow & window)
{
	if (white_ball)
		window.draw(c);
	else if (ball_exist &&(!white_ball))
	{
		window.draw(c);
	}
}



Ball::~Ball()
{
}
