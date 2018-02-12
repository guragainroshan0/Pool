#pragma once
#include<SFML\Graphics.hpp>
class Board
{
private:
	sf::Vector2f board_size;
	sf::Texture board_texture;
	const char *file;
public:
	Board(const char *file_path, sf::Vector2f size);
	~Board();
};

