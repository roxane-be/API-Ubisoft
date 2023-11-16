#include "stdafx.h"
#include "Button.h"
#include "App/app.h"

Button::Button()
{
	sprite = nullptr;

	transform = Transform();
	text = "text";
	positionText.SetVector2f(0, 0);
}

void Button::Init()
{
	sprite = App::CreateSprite(".\\TestData\\UI\\Button.png", 1, 1);
	sprite->SetPosition(transform.GetPosition().x, transform.GetPosition().y);
	sprite->SetScale(1.f);
	size.SetVector2f(sprite->GetWidth()/2, sprite->GetHeight()/2);
}

void Button::Render()
{
	sprite->Draw();
	App::Print(positionText.x + transform.GetPosition().x, positionText.y + transform.GetPosition().y, text);

	float r = 1.0f;
	float g = 0.0f;
	float b = 0.0f;

	App::DrawLine(transform.GetPosition().x - size.x ,transform.GetPosition().y - size.y , transform.GetPosition().x+ size.x, transform.GetPosition().y - size.y, r, g, b);
	App::DrawLine(transform.GetPosition().x + size.x ,transform.GetPosition().y - size.y , transform.GetPosition().x+ size.x, transform.GetPosition().y + size.y, r, g, b);
	App::DrawLine(transform.GetPosition().x + size.x ,transform.GetPosition().y + size.y , transform.GetPosition().x- size.x, transform.GetPosition().y + size.y, r, g, b);
	App::DrawLine(transform.GetPosition().x - size.x ,transform.GetPosition().y + size.y , transform.GetPosition().x- size.x, transform.GetPosition().y - size.y, r, g, b);
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
	sprite->SetPosition(transform.GetPosition().x, transform.GetPosition().y);
}

bool Button::IsHovered()
{
	Vector2f posMouse(0, 0);
	App::GetMousePos(posMouse.x, posMouse.y);
	//App::GetMousePos(posMouse.X(), posMouse.Y());

	if (   posMouse.x > transform.GetPosition().x - size.x
		&& posMouse.x < transform.GetPosition().x + size.x
		&& posMouse.y > transform.GetPosition().y - size.y
		&& posMouse.y < transform.GetPosition().y + size.y
		)
		return true;

	return false;
}