#include<SFML\Graphics.hpp>
#include<iostream>
#define HEIGHT 600
#define WIDTH 900

class ball
{
private:
	float radius;
	sf::Texture circle_texture;
	const char *file;
	sf::Vector2f position;
public:
	sf::CircleShape c;
	ball(float r, sf::Texture texture, const char *file_path, sf::Vector2f pos)
	{
		radius = r;
		circle_texture = texture;
		file = file_path;
		std::cout << file << std::endl << file_path;
		position = pos;
		circle_texture.loadFromFile(file_path);
		c.setTexture(&circle_texture);
		c.setPosition(pos);
		c.setRadius(radius);
	}
};
class board
{
private:
	sf::Vector2f board_size;
	sf::Texture board_texture;
	const char *file;
public:
	sf::RectangleShape rectangle;
	board( const char *file_path, sf::Vector2f size)
	{
	
		file = file_path;
		std::cout << file << std::endl << file_path;
		board_size = size;
		board_texture.loadFromFile(file_path);
		rectangle.setTexture(&board_texture);
		rectangle.setSize(board_size);
		
	}
};
int main()
{

	sf::RenderWindow window;
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Roshan");
	sf::Texture texture_rect , texture_circle;
	board board("board.png", sf::Vector2f(900.0f, 600.0f));
	ball b1(15.0, texture_circle, "ball.png", sf::Vector2f(300, 150));
	ball b2(15.0, texture_circle, "ball.png", sf::Vector2f(30, 150));

	while (window.isOpen())
	{
		sf::Event event;
		window.draw(board.rectangle);
		window.draw(b1.c);
		window.draw(b2.c);
		window.display();
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;


			default:
				break;
			}

		}
		
		
		window.draw(board.rectangle);
		window.draw(b1.c);
		window.draw(b2.c);
		window.display();
		window.clear();
	}
	return 0;

}