#pragma once

struct Vector2f
{
	Vector2f(float x = 0, float y = 0);
	Vector2f GetPosition() { return Vector2f(X, Y); }
	void SetPosition(float x, float y) { X = x; Y = y; } 
	float X;
	float Y;

};

class Entity
{
public:
	Entity();

public:
	Vector2f position;

protected:
	int life;


};



