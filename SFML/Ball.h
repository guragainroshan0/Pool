#pragma once
#include<SFML\Graphics.hpp>
class Ball
{
private:
	float radius;
	sf::Texture circle_texture;
	const char *file;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f accleration;
	sf::Vector2f daccleration;
	bool white_ball = false;
	float mass = 0.5;
	
public:
	sf::Sprite c;
	Ball();
	Ball(float r, sf::Texture texture, const char *file_path, sf::Vector2f pos);
	void white()
	{
		white_ball = true;
	}
	void draw(sf::RenderWindow & window);
	bool collission(Ball &b);
	void change_velocity();
	void transfer_momentum( Ball &b);
	void update();

	~Ball();
};

