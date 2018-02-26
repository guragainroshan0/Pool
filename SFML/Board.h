#pragma once
#include<SFML\Graphics.hpp>
#include <vector>
class Board
{
private:
	//sf::RectangleShape r;
   // r.setSize(sf::Vector2f(700.0f, 1480.0f));
	sf::Vector2f board_size;
	const char *file;
	static sf::Texture board_texture;
	sf::RectangleShape shape;
	
public:
	Board(const char *file_path, sf::Vector2f size);
	void draw(sf::RenderWindow &window);
	
	~Board();
};

