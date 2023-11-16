#pragma once

struct Vector2f
{
public: 
	Vector2f(float x = 0, float y = 0);
	Vector2f GetVector2f() { return Vector2f(x, y); }
	void SetVector2f(float x, float y) { this->x = x; this->y = y; } 

	float x;
	float y;

};

class Vector2
{
public:
	Vector2();


};



