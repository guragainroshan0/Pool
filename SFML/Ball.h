#pragma once
#include "vec.h"
#include<vector>
#include<SFML\Graphics.hpp>
class Ball
{
private:
	float radius;
	
	
	
	static sf::Texture circle_texture;
	
	float mass = 0.5;
	std::vector <Ball> balls;
	std::vector <vec> pos;
	bool ball_exist = true;

	
public:
	const char *file;
	bool show = true;
	bool exists = true;
	vec ballCenter;
	int id;
	bool white_ball;
	vec position;
	vec velocity;
	vec accleration;
	sf::Sprite c;
	
	Ball();
	void add_pos();
	void hole_pos(vec);
	Ball(float r, const char *file_path, sf::Vector2f pos ,bool wh);
	void white()
	{
		white_ball = true;
	}
	vec getPos()
	{
		return position;
	}
	void setPos(vec pos)
	{
		position = pos;
	}
	float getRadius()
	{
		return radius;
	}
	void setId(int i)
	{
		id = i;
	}
	

	void update(float deltatime, sf::RenderWindow & window);
	void draw(sf::RenderWindow & window);
    bool collission(Ball &b);
	//void change_velocity();
	void transfer_momentum(Ball &b);

	
	~Ball();
};

/*//distance between ball
float distance = ball.position.distance(target.position);
//if balls overlap
float overlap = 0.5f * (distance - ball.getRadius() - target.getRadius());
//hitting ball

vec temp;
temp = ball.position - ((ball.position - target.position).normal())* overlap;
ball.setPos(sf::Vector2f(temp.x, temp.y));
//target ball
vec temp1;
temp1 = ball.position + ((ball.position - target.position).normal())* overlap;
target.setPos(sf::Vector2f(temp1.x, temp1.y));


vec tempa;
tempa = ball.velocity;
target.velocity = ball.velocity;
ball.velocity = tempa;*/