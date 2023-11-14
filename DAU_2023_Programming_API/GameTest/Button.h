#pragma once
#include <functional>

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
	CSimpleSprite* sprite;
	const char* text;
	Vector2f position;
	Vector2f positionText;
	Vector2f size;
};
