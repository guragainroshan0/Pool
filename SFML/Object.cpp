#include "Object.h"
#include "vec.h"
//#include "holes.h"
#include <iostream>


Object::Object()
{
}

void Object::addBall(sf::Vector2f pos,const char *file ,bool white)
{
	
	Ball b(15.0f, file, pos ,white);
	b.setId(balls.size());
	balls.push_back(b);
	
}

void Object::update(float deltatime , sf::RenderWindow &window)
{
	

	ballUpdate(deltatime , window);
}



void Object::pot()
{
	int t = 0;
	for (auto &ball : balls)
	{
		t++;
		for (auto &hol : hole)
		{
			if (hol.position == ball.position)
			{
				balls.erase(balls.begin()+t);
			}
		}
	}
}

void Object::ballUpdate(float deltatime,sf::RenderWindow &window)
{	
	

	if (balls.size() <= 1)
	{
		gameOver = true;
	}
	int i = 0;
	for (auto &ball : balls)
	{
		for (auto &hp : hole)
		{
			//std::cout << hp.position.x << std::endl;
			/*hp.position.x += 15;
			hp.position.y += 15;

			ball.position.x += 15;
			ball.position.y += 15;*/
			
			//if (sqrt((ball.position.x + 15 - hp.position.x+35)*(ball.position.x + 15 - hp.position.x + 35) + (ball.position.y + 15 - hp.position.y + 35)*(ball.position.y + 15 - hp.position.y + 35))<40.0f)
			if(ball.c.getGlobalBounds().intersects(hp.hole.getGlobalBounds()))
			{
				std::cout << ball.position.distance(hp.position) << std::endl;
				if (!ball.white_ball)
				{
					balls.erase(balls.begin() + i);
					score += 10;
				}
				else if (ball.white_ball)
				{
					balls.erase(balls.begin() + i);
					whiteballexists = false;


				}

			}
		}
		if (!whiteballexists)
		{
			sf::Vector2f a(400.0f, 350.0f);
			Ball wh(15.0f, "ball.png", a, true);
			//wh.velocity = 0;
			balls.push_back(wh);
			whiteballexists = true;
			std::cout << wh.position.x << "  " << wh.position.y << std::endl;
		}
		ball.update(deltatime ,window);
		
		for (auto &target : balls)
		{
			if (ball.id != target.id)
			{
				
				if (ball.collission(target))

				{
					//distance between ball
					float distance =ball.position.distance(target.position);
					//if balls overlap
					float overlap = 0.5f * (distance - ball.getRadius() - target.getRadius());
					//hitting ball
					float x1, x2, y1, y2;

					x1 = ball.getPos().x - (overlap * (ball.getPos().x - target.getPos().x) / distance);
					y1 = ball.getPos().y -(overlap * (ball.getPos().y - target.getPos().y) / distance);
					ball.setPos(sf::Vector2f(x1, y1));
					//target ball
					x2 = target.getPos().x + (overlap * (ball.getPos().x - target.getPos().x) / distance);
					y2 = target.getPos().y + (overlap * (ball.getPos().y - target.getPos().y) / distance);
					target.setPos(sf::Vector2f(x2, y2));

					ball.transfer_momentum(target);


					collided_balls.push_back({ &ball,&target });
				}
			}
			
		}
		
		i++;
		
		
	}
	for (auto c : collided_balls)
	{
		Ball *b1 = c[0];
		Ball *b2 = c[1];

		
	}

}
void Object::makeHole(sf::Vector2f pos ,float radius)
{
	holes h(pos ,radius);
	hole.push_back(h);
}
void Object::addBoard()
{
	Board b("board.png", sf::Vector2f(1480.0f, 700.0f));
	board.push_back(b);
}


void Object::display(sf::RenderWindow & window)
{
	
	
	board[0].draw(window);
	for (auto &ball : balls)
	{
		ball.draw(window);
	}	
	for (auto &hp : hole)
	{
		hp.draw(window);
	}
	

}



Object::~Object()
{
}
