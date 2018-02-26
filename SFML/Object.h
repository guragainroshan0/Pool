#pragma once

#include <SFML\Graphics.hpp>
#include "Ball.h"
#include "Board.h"
#include "holes.h"
#include<vector>
class Object
{
private:
	std::vector <Ball> balls;
	std::vector <Board> board;
	std::vector <std::vector< Ball *>> collided_balls;
	std::vector <holes> hole;
	bool whiteballexists = true;
public:
	bool gameOver =false;
	float score = 0;

	
	Object();
	
	void addBall(sf::Vector2f pos,const char *fi ="8ball.png" ,bool white =false);
	void update(float deltatime , sf::RenderWindow &window);
	void makeHole(sf::Vector2f pos ,float radius);
	void pot();

	void ballUpdate(float deltatime ,sf::RenderWindow &window);
	

	void display(sf::RenderWindow &window);
	void addBoard();
	~Object();
};

