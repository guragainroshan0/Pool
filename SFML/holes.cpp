#include "holes.h"



holes::holes(sf::Vector2f pos ,float radius)
{
	rad = radius;
	position = pos;
	hole.setPosition(pos);
	hole.setRadius(radius);
	//hole.setFillColor()
};


void holes::draw(sf::RenderWindow & window)
{
	window.draw(hole);
}

holes::~holes()
{
}
