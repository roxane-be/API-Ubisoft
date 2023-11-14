#include "stdafx.h"
#include "Button.h"
#include "App/app.h"

Button::Button()
{
	sprite = nullptr;
	position.SetPosition(0, 0);
	text = "text";
	positionText.SetPosition(0, 0);
}

void Button::Init()
{
	sprite = App::CreateSprite(".\\TestData\\UI\\Button.png", 1, 1);
	sprite->SetPosition(position.X, position.Y);
	sprite->SetScale(1.f);
	size.SetPosition(sprite->GetWidth()/2, sprite->GetHeight()/2);
}

void Button::Render()
{
	sprite->Draw();
	App::Print(positionText.X + position.X, positionText.Y + position.Y, text);

	float r = 1.0f;
	float g = 0.0f;
	float b = 0.0f;

	App::DrawLine(position.X - size.X , position.Y - size.Y , position.X + size.X, position.Y - size.Y, r, g, b);
	App::DrawLine(position.X + size.X , position.Y - size.Y , position.X + size.X, position.Y + size.Y, r, g, b);
	App::DrawLine(position.X + size.X , position.Y + size.Y , position.X - size.X, position.Y + size.Y, r, g, b);
	App::DrawLine(position.X - size.X , position.Y + size.Y , position.X - size.X, position.Y - size.Y, r, g, b);
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
	position = _position;
	sprite->SetPosition(position.X, position.Y);
}

bool Button::IsHovered()
{
	Vector2f posMouse(0, 0);
	App::GetMousePos(posMouse.X, posMouse.Y);

	if (posMouse.X > position.X - size.X
		&& posMouse.X < position.X + size.X
		&& posMouse.Y > position.Y - size.Y
		&& posMouse.Y < position.Y + size.Y
		)
		return true;

	return false;
}