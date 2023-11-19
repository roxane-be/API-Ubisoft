#pragma once
#include <functional>
#include "Transform.h"
#include "VisualSprite.h"

class Button
{
public:
	Button();

	void Init();
	void Render();
	void OnClick();
	void SetText(const char* _text);
	//Marge
	void SetTextPosition(Vector2f _position);
	void SetPosition(Vector2f _position);
	Vector2f GetTextPosition() { return positionText; };

	bool IsHovered();	
	std::function<void()> ptrF;

private:
	VisualSprite sprite;
	const char* text;
	Transform transform;
	Vector2f positionText;
	Vector2f size;
};
