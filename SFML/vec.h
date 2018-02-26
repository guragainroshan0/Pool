#pragma once
#include <cmath>
#include <SFML\Graphics.hpp>
class vec
{
private:
	
public:
	float x, y;
	vec(float a = 0, float b = 0)
	{
		x = a;
		x = b;
	}
	vec(sf::Vector2f a)
	{
		x = a.x;
		y = a.y;
	}

	float dot(vec a)
	{
		return x * a.x + y * a.y;
	}
	float length()
	{
		return sqrt((x+15)*(15+x) + (y+15) * (y+15));
	}
	float length(float a, float b)
	{
		return sqrt(a*a + b * b);
	}
	vec normal(vec a)
	{
		vec b;
		b.x = (x-a.x) /length(x-a.x , y-a.y) ;
		b.y = (y -a.y)/ length(x - a.x, y - a.y);
		return b;

	}
	
	vec operator +(vec a)
	{
		x = x + a.x;
		y = y + a.y;
		return *this;
	}
	vec operator +(sf::Vector2f a)
	{
		x = x + a.x;
		y = y + a.y;
		return *this;
	}
	vec operator -(vec a)
	{
		x = x - a.x;
		y = y - a.y;
		return *this;
	}
	vec operator *(vec a)
	{
		x = x * a.x;
		y = y * a.y;
		return *this;
	}
	 vec operator*(float a)
	{
		x = x * a;
		y = y * a;
		return *this;
	}
	 vec operator/(float a)
	 {
		 x = x / a;
		 y = y / a;
		 return *this;
	 }
	 vec operator + (float a)
	 {
		 x += a;
		 y += a;
		 return *this;
	 }

	 float distance(vec a)
	 {
		 float p = (x - a.x)*(x - a.x) + (y - a.y)*(y - a.y);
		 return sqrt(p);
	 }
	 vec direction(vec a)
	 {
		// vec  c;
		 x = (x - a.x) / distance(a);
		 y = (y - a.y) / distance(a);
		 return *this;
	 }
	 operator sf::Vector2f()
	 {
		 return sf::Vector2f(x, y);
	 }
	bool operator ==(vec a)
	 {
		 if (x == a.x && y == a.y)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	 }

};