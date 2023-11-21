#include "stdafx.h"
#include "Character.h"
#include "App/app.h"

Character::Character()
{
	transform = Transform(Vector2f(200, 400), Vector2f(0, 0), Vector2f(1, 1));
	transform.SetPosition(Vector2f(200, 400));
	//testSprite = nullptr;
	sprite = VisualSprite();
	//other.SetPosition(700, 400);
}

Character::~Character()
{
}

void Character::Init()
{
	sprite.CreateSprite(".\\TestData\\Test.bmp", 8, 4, 1.0f, ".\\TestData\\Test.txt");
}

void Character::Update(float deltaTime)
{
	sprite.Update(deltaTime);
}

void Character::Render()
{
	sprite.RenderSprite(transform.GetPosition());

	//for print rect like collision
	{
		float r = 0.0f;
		float g = 1.0f;
		float b = 0.0f;
		int decalage = 35;

		//colplayer
		App::DrawLine(transform.GetPosition().x - decalage, transform.GetPosition().y - decalage * 2, transform.GetPosition().x + decalage, transform.GetPosition().y - decalage * 2, r, g, b);
		App::DrawLine(transform.GetPosition().x + decalage, transform.GetPosition().y - decalage * 2, transform.GetPosition().x + decalage, transform.GetPosition().y + decalage * 2, r, g, b);
		App::DrawLine(transform.GetPosition().x + decalage, transform.GetPosition().y + decalage * 2, transform.GetPosition().x - decalage, transform.GetPosition().y + decalage * 2, r, g, b);
		App::DrawLine(transform.GetPosition().x - decalage, transform.GetPosition().y + decalage * 2, transform.GetPosition().x - decalage, transform.GetPosition().y - decalage * 2, r, g, b);
	}
}
