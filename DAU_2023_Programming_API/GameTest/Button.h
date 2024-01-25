#pragma once
#include <functional>
#include "Transform.h"
#include "VisualSprite.h"

class Button : public Component
{
public:
	Button() = default;
	Button(Entity* parent) : Component(parent) {};

	//override function pure parent
	virtual void Init()override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;
	virtual Component* Clone(Entity* resultEntity) override;

	void OnClick();
	void SetText(std::string _text);

	void SetOffsetTextPosition(Vector2f _position);
	Vector2f GetTextPosition() { return m_offsetPositionText; };

	bool IsHovered();
	std::function<void()> ptrF;

private:
	std::string m_text = "Button";
	Vector2f m_offsetPositionText;	 
};
