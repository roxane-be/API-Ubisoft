#pragma once

struct Vector2f
{
public: 
	Vector2f(float _x = 0, float _y = 0) : x(_x), y(_y){};
	Vector2f GetVector2f() { return Vector2f(x, y); }
	void SetVector2f(float x, float y) { this->x = x; this->y = y; } 

	float x;
	float y;

};




