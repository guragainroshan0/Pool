#pragma once
#include "vec.h"
#include <SFML\Graphics.hpp>
class holes
{
private:
	
	float rad;

public:
	sf::CircleShape hole;
	//std::vector <sf::Vector2f> h;
	vec position;
	holes(sf::Vector2f pos , float radius);

	void draw(sf::RenderWindow &window);
	~holes();
};

