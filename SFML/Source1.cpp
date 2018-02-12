#include<SFML\Graphics.hpp>
#include "Ball.h"
#include<iostream>
#include <vector>
#define HEIGHT 700
#define WIDTH 1480
#define FIRST_X 950
#define FIRST_Y 325
#define SECOND_X 980
#define SECOND_Y 310
#define THIRD_X 1010
#define THIRD_Y 295
#define FOURTH_X 1040
#define FOURTH_Y 280
#define FIVE_X 1070
#define FIVE_Y 265

class board
{
private:
	sf::Vector2f board_size;
	sf::Texture board_texture;
	const char *file;
public:
	sf::RectangleShape rectangle;
	board(const char *file_path, sf::Vector2f size)
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

class cue
{
private:
	sf::Texture cuetexture;
	const char *file;
public:
	sf::Sprite scue;
	cue(const char *file_path)
	{
		//file = file_path;
		if (!cuetexture.loadFromFile(file_path))
		{
			std::cout << "Failed" << std::endl;
		}
		scue.setTexture(cuetexture);
		scue.setPosition(-100.0, 300.0);
		scue.setScale(sf::Vector2f(0.3f, 0.3f));
		
		scue.rotate(45);
	}
};

int main()
{
	float ballposx = 0, ballposy = 0;
	//rendering window object made
	sf::RenderWindow window;
	//create window with certain width and height and name 
	window.create(sf::VideoMode(WIDTH, HEIGHT), "Roshan");
	sf::Texture texture_rect, texture_circle;
	board board("board.png", sf::Vector2f(1480.0f, 700.0f));
	board.getSize();
	/*std::vector <Ball> b;
	
	Ball b0(15.0, texture_circle, "ball.png", sf::Vector2f(FIVE_X, FIVE_Y));
	Ball b1(15.0, texture_circle, "ball.png", sf::Vector2f(FIVE_X, FIVE_Y + 30));
	Ball b2(15.0, texture_circle, "ball.png", sf::Vector2f(FIVE_X, FIVE_Y + 60));
	Ball b3(15.0, texture_circle, "ball.png", sf::Vector2f(FIVE_X, FIVE_Y + 90));
	Ball b4(15.0, texture_circle, "ball.png", sf::Vector2f(FIVE_X, FIVE_Y + 120));

	Ball b5(15.0, texture_circle, "ball.png", sf::Vector2f(FOURTH_X, FOURTH_Y));
	Ball b6(15.0, texture_circle, "ball.png", sf::Vector2f(FOURTH_X, FOURTH_Y + 30));
	Ball b7(15.0, texture_circle, "ball.png", sf::Vector2f(FOURTH_X, FOURTH_Y + 60));
	Ball b8(15.0, texture_circle, "ball.png", sf::Vector2f(FOURTH_X, FOURTH_Y + 90));

	Ball b9(15.0, texture_circle, "ball.png", sf::Vector2f(THIRD_X, THIRD_Y));
	Ball b10(15.0, texture_circle, "ball.png", sf::Vector2f(THIRD_X, THIRD_Y + 30));
	Ball b11(15.0, texture_circle, "ball.png", sf::Vector2f(THIRD_X, THIRD_Y + 60));

	Ball b12(15.0, texture_circle, "ball.png", sf::Vector2f(SECOND_X, SECOND_Y));
	Ball b13(15.0, texture_circle, "ball.png", sf::Vector2f(SECOND_X, SECOND_Y + 30));*/

	Ball b14(15.0, texture_circle, "ball.png", sf::Vector2f(FIRST_X, FIRST_Y));

	Ball b15(15.0, texture_circle, "ball.png", sf::Vector2f(400.0f, 350.0f));
	b15.white();
	

	cue cue("cue.png");




	while (window.isOpen())
	{
		sf::Event event;
		window.draw(board.rectangle);
		/*b0.draw(window);
		b1.draw(window);
		b2.draw(window);
		b3.draw(window);
		b4.draw(window);
		b5.draw(window);
		b6.draw(window);
		b7.draw(window);
		b8.draw(window);
		b9.draw(window);
		b10.draw(window);
		b11.draw(window);
		b12.draw(window);
		b13.draw(window);*/
		b14.draw(window);
		b15.draw(window);
		b15.update();
		b15.collission(b14);
		//b16.draw(window);
		window.draw(cue.scue);
		//window.draw(b.c);
		window.display();
		while (window.pollEvent(event))
		{
			

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;
			case sf::Event::MouseMoved:
				std::cout << event.mouseMove.x << "   " << event.mouseMove.y << std::endl;
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Space:
					
					
					break;


				default:
					break;
				}

			
				
			default:
				break;
			}

		}


		window.draw(board.rectangle);
		/*b0.draw(window);
		b1.draw(window);
		b2.draw(window);
		b3.draw(window);
		b4.draw(window);
		b5.draw(window);
		b6.draw(window);
		b7.draw(window);
		b8.draw(window);
		b9.draw(window);
		b10.draw(window);
		b11.draw(window);
		b12.draw(window);
		b13.draw(window);*/
		b14.draw(window);
		b15.draw(window);
		/*for(int i=0;i<b.size();i++)
		{
			for (int j = i; j < b.size() -1; j++)
			{
				b[i].collission(b[j + 1]);
				
			}
			

		}
		for (int i = 0; i<b.size(); i++)
		{
			b[i].update();


		}*/
		b15.collission(b14);
		b14.update();
		//b16.draw(window);


		window.draw(cue.scue);
		window.display();
		window.clear();
	}
	return 0;

}