#pragma once
#include <functional>
#include "Transform.h"
#include "VisualSprite.h"

class Button : public Component
{
public:
	Button() = default;
	Button(Entity* parent, BlackBoard* _blackBoard)
	{ 
		m_entity = parent;  
		m_blackBoard = _blackBoard;	
	};

	void Init();
	void Update(float deltaTime);
	void Render();
	void OnClick();
	void SetText(const char* _text);
	//Marge
	void SetOffsetTextPosition(Vector2f _position);
	Vector2f GetTextPosition() { return offsetPositionText; };

	bool IsHovered();	
	std::function<void()> ptrF;

private:
	//VisualSprite sprite;
	const char* text = "Button";
	//Transform transform = Transform();
	Vector2f offsetPositionText = Vector2f();
	Vector2f size = Vector2f(100,100);
};
