#include "stdafx.h"
#include "Button.h"
#include "App/app.h"

Button::Button()
{
	transform = Transform();
	text = "text";
	positionText.SetVector2f(0, 0);
}

void Button::Init()
{

	//sprite->SetPosition(transform.GetPosition().x, transform.GetPosition().y);

	sprite.CreateSprite(".\\TestData\\UI\\Button.png", 1, 1);
	size.SetVector2f(sprite.GetSize().x / 2, sprite.GetSize().y / 2);
	//size.SetVector2f(50, 100);
}

void Button::Update(float deltaTime)
{
	if (App::IsKeyPressed(VK_LBUTTON) && IsHovered())
		OnClick();

}

void Button::Render()
{
	sprite.RenderSprite(transform.GetPosition());
	App::Print(positionText.x + transform.GetPosition().x, positionText.y + transform.GetPosition().y, text);

	float r = 1.0f;
	float g = 0.0f;
	float b = 0.0f;

	App::DrawLine(transform.GetPosition().x - size.x, transform.GetPosition().y - size.y, transform.GetPosition().x + size.x, transform.GetPosition().y - size.y, r, g, b);
	App::DrawLine(transform.GetPosition().x + size.x, transform.GetPosition().y - size.y, transform.GetPosition().x + size.x, transform.GetPosition().y + size.y, r, g, b);
	App::DrawLine(transform.GetPosition().x + size.x, transform.GetPosition().y + size.y, transform.GetPosition().x - size.x, transform.GetPosition().y + size.y, r, g, b);
	App::DrawLine(transform.GetPosition().x - size.x, transform.GetPosition().y + size.y, transform.GetPosition().x - size.x, transform.GetPosition().y - size.y, r, g, b);
}

void Button::OnClick()
{
	ptrF();
}

void Button::SetText(const char* _text)
{
	text = _text;
}

void Button::SetTextPosition(Vector2f _position)
{
	positionText = _position;
}

void Button::SetPosition(Vector2f _position)
{
	transform.SetPosition(_position);
	//sprite->SetPosition(transform.GetPosition().x, transform.GetPosition().y);
}

bool Button::IsHovered()
{
	Vector2f posMouse(0, 0);
	App::GetMousePos(posMouse.x, posMouse.y);
	//App::GetMousePos(posMouse.X(), posMouse.Y());

	if (posMouse.x > transform.GetPosition().x - size.x
		&& posMouse.x < transform.GetPosition().x + size.x
		&& posMouse.y > transform.GetPosition().y - size.y
		&& posMouse.y < transform.GetPosition().y + size.y
		)
		return true;

	return false;
}