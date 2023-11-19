#include "stdafx.h"
#include "MainCharacter.h"
#include "App/app.h"
#include "App/SimpleSprite.h"

MainCharacter::MainCharacter()
{
	transform = Transform(Vector2f(200, 400), Vector2f(0, 0), Vector2f(1, 1));
	transform.SetPosition(Vector2f(200, 400));
	//testSprite = nullptr;
	vSprite = VisualSprite();
	//other.SetPosition(700, 400);
}

void MainCharacter::InitSprite()
{
	vSprite.CreateSprite(".\\TestData\\Test.bmp", 8, 4, 1.0f, ".\\TestData\\Test.txt");
}

void MainCharacter::UpdateSprite(float deltaTime)
{
	//------------------------------------------------------------------------
	// Example Sprite Code....
	vSprite.Update(deltaTime);
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		vSprite.SetAnimation(ANIM_RIGHT);
		transform.SetPosition(transform.GetPosition().x + 1, transform.GetPosition().y);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		vSprite.SetAnimation(ANIM_LEFT);
		transform.SetPosition(transform.GetPosition().x - 1, transform.GetPosition().y);

	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		vSprite.SetAnimation(ANIM_FORWARDS);
		transform.SetPosition(transform.GetPosition().x, transform.GetPosition().y + 1);

	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		vSprite.SetAnimation(ANIM_BACKWARDS);
		transform.SetPosition(transform.GetPosition().x, transform.GetPosition().y - 1);

	}
	/*if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
	{
		testSprite->SetScale(testSprite->GetScale() + 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
	{
		testSprite->SetScale(testSprite->GetScale() - 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
	{
		testSprite->SetAngle(testSprite->GetAngle() + 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
	{
		testSprite->SetAngle(testSprite->GetAngle() - 0.1f);
	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
	{
		testSprite->SetAnimation(-1);
	}*/



}

void MainCharacter::RenderSprite()
{
	vSprite.RenderSprite(transform.GetPosition());

	float r = 0.0f;
	float g = 1.0f;
	float b = 0.0f;
	int decalage = 35;

	//colplayer
	App::DrawLine(transform.GetPosition().x - decalage, transform.GetPosition().y - decalage * 2, transform.GetPosition().x + decalage, transform.GetPosition().y - decalage * 2, r, g, b);
	App::DrawLine(transform.GetPosition().x + decalage, transform.GetPosition().y - decalage * 2, transform.GetPosition().x + decalage, transform.GetPosition().y + decalage * 2, r, g, b);
	App::DrawLine(transform.GetPosition().x + decalage, transform.GetPosition().y + decalage * 2, transform.GetPosition().x - decalage, transform.GetPosition().y + decalage * 2, r, g, b);
	App::DrawLine(transform.GetPosition().x - decalage, transform.GetPosition().y + decalage * 2, transform.GetPosition().x - decalage, transform.GetPosition().y - decalage * 2, r, g, b);

	r = 1.0f;
	g = 1.0f;
	b = 0.0f;


	/*App::DrawLine(other.X - decalage, other.Y - decalage * 2, other.X + decalage, other.Y - decalage * 2, r, g, b);
	App::DrawLine(other.X + decalage, other.Y - decalage * 2, other.X + decalage, other.Y + decalage * 2, r, g, b);
	App::DrawLine(other.X + decalage, other.Y + decalage * 2, other.X - decalage, other.Y + decalage * 2, r, g, b);
	App::DrawLine(other.X - decalage, other.Y + decalage * 2, other.X - decalage, other.Y - decalage * 2, r, g, b);
	if (other.X - decalage >= position.X + decalage)

		other.SetPosition(other.X - 1, other.Y);*/
}
