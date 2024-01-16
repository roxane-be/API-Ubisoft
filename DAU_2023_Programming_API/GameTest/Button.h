#pragma once
#include <functional>
#include "Transform.h"
#include "VisualSprite.h"

class Button : public Component
{
public:
	Button() = default;
	Button(Entity* parent, BlackBoard* _blackBoard) : Component(parent, _blackBoard) {};

	virtual void Init()override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

	virtual Component* Clone(Entity* resultEntity) override;

	void OnClick();
	void SetText(std::string _text);

	//Marge
	void SetOffsetTextPosition(Vector2f _position);
	Vector2f GetTextPosition() { return offsetPositionText; };

	bool IsHovered();
	std::function<void()> ptrF;

private:
	std::string text = "Button";
	Vector2f offsetPositionText;
	Vector2f size {100, 100};
};
