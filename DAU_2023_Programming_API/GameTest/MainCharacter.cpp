#include "stdafx.h"
#include "MainCharacter.h"
#include "App/app.h"
#include "App/SimpleSprite.h"

MainCharacter::MainCharacter()
{
	transform = Transform(Vector2f(200, 400), Vector2f(0, 0), Vector2f(1, 1));
	transform.SetPosition(Vector2f(200, 400));
	testSprite = nullptr;
	//other.SetPosition(700, 400);
}

void MainCharacter::InitSprite()
{
	//------------------------------------------------------------------------
		// Example Sprite Code....
	testSprite = App::CreateSprite(".\\TestData\\Test.bmp", 8, 4);
	testSprite->SetPosition(transform.GetPosition().x, transform.GetPosition().y);
	float speed = 1.0f / 15.0f;
	testSprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4,5,6,7 });
	testSprite->CreateAnimation(ANIM_LEFT, speed, { 8,9,10,11,12,13,14,15 });
	testSprite->CreateAnimation(ANIM_RIGHT, speed, { 16,17,18,19,20,21,22,23 });
	testSprite->CreateAnimation(ANIM_FORWARDS, speed, { 24,25,26,27,28,29,30,31 });
	testSprite->SetScale(1.0f);
	//------------------------------------------------------------------------

}

void MainCharacter::UpdateSprite(float deltaTime)
{
	//------------------------------------------------------------------------
	// Example Sprite Code....
	testSprite->Update(deltaTime);
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		testSprite->SetAnimation(ANIM_RIGHT);
		transform.SetPosition(transform.GetPosition().x + 1, transform.GetPosition().y);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		testSprite->SetAnimation(ANIM_LEFT);
		transform.SetPosition(transform.GetPosition().x - 1, transform.GetPosition().y);

	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		testSprite->SetAnimation(ANIM_FORWARDS);
		transform.SetPosition(transform.GetPosition().x, transform.GetPosition().y + 1);

	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		testSprite->SetAnimation(ANIM_BACKWARDS);
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
	//------------------------------------------------------------------------
	// Example Sprite Code....
	testSprite->SetPosition(transform.GetPosition().x, transform.GetPosition().y);
	testSprite->Draw();
	//------------------------------------------------------------------------


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
