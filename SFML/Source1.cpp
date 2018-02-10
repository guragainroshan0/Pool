#include<SFML\Graphics.hpp>
#include<iostream>
#define HEIGHT 600
#define WIDTH 900
#define FIRST_X 550
#define FIRST_Y 225
#define SECOND_X 580
#define SECOND_Y 240
#define THIRD_X 610
#define THIRD_Y 255

class ball
{
	//private variables for ball
private:
	float radius;
	sf::Texture circle_texture;
	const char *file;
	sf::Vector2f position;
public:
	//circle object is public as it is to be accessed by other functions like window.display
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
	void getSize()
	{
		sf::Vector2u siz = board_texture.getSize();
		std::cout << siz.x << std::endl << siz.y << std::endl;
	}
};
int main()
{
	//rendering window object made
	sf::RenderWindow window;
	//create window with certain width and height and name 
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Roshan");
	sf::Texture texture_rect , texture_circle;
	board board("board.png", sf::Vector2f(900.0f, 600.0f));
	board.getSize();
	ball b0(15.0, texture_circle, "ball.png", sf::Vector2f(FIRST_X, FIRST_Y));
	ball b1(15.0, texture_circle, "ball.png", sf::Vector2f(FIRST_X, FIRST_Y+30));
	ball b2(15.0, texture_circle, "ball.png", sf::Vector2f(FIRST_X, FIRST_Y + 60));
	ball b3(15.0, texture_circle, "ball.png", sf::Vector2f(FIRST_X, FIRST_Y + 90));
	ball b4(15.0, texture_circle, "ball.png", sf::Vector2f(FIRST_X, FIRST_Y + 120));

	ball b5(15.0, texture_circle, "ball.png", sf::Vector2f(SECOND_X, SECOND_Y));
	ball b6(15.0, texture_circle, "ball.png", sf::Vector2f(SECOND_X, SECOND_Y + 30));
	ball b7(15.0, texture_circle, "ball.png", sf::Vector2f(SECOND_X, SECOND_Y + 60));
	ball b8(15.0, texture_circle, "ball.png", sf::Vector2f(SECOND_X, SECOND_Y+ 90));
	
	ball b9(15.0, texture_circle, "ball.png", sf::Vector2f(THIRD_X, THIRD_Y ));
	ball b10(15.0, texture_circle, "ball.png", sf::Vector2f(THIRD_X, THIRD_Y + 30));
	ball b11(15.0, texture_circle, "ball.png", sf::Vector2f(THIRD_X, THIRD_Y + 60));

	while (window.isOpen())
	{
		sf::Event event;
		window.draw(board.rectangle);
		window.draw(b0.c);
		window.draw(b1.c);
		window.draw(b2.c);
		window.draw(b3.c);
		window.draw(b4.c);
		window.draw(b5.c);
		window.draw(b6.c);
		window.draw(b7.c);
		window.draw(b8.c);
		//window.draw(b.c);
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
		window.draw(b0.c);
		window.draw(b1.c);
		window.draw(b2.c);
		window.draw(b3.c);
		window.draw(b4.c);
		window.draw(b5.c);
		window.draw(b6.c);
		window.draw(b7.c);
		window.draw(b8.c);
		window.display();
		window.clear();
	}
	return 0;

}