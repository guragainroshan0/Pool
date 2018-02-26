#include "Board.h"
sf::Texture Board::board_texture;
Board::Board(const char * file_path, sf::Vector2f size)
{
	file = file_path;
	board_size = size;
	board_texture.loadFromFile(file);
	shape.setTexture(&board_texture);
	shape.setSize(board_size);
}

void Board::draw(sf::RenderWindow & window)
{
	window.draw(shape);
}

Board::~Board()
{
}
