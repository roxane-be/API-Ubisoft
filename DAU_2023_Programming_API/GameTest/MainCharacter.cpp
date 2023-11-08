#include "stdafx.h"
#include "MainCharacter.h"
#include "App/app.h"
#include "App/SimpleSprite.h"

MainCharacter::MainCharacter()
{
	position.SetPosition(400,400);
	testSprite = nullptr;
}

void MainCharacter::InitSprite()
{
	//------------------------------------------------------------------------
		// Example Sprite Code....
	testSprite = App::CreateSprite(".\\TestData\\Test.bmp", 8, 4);
	testSprite->SetPosition(position.X, position.Y);
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
		position.SetPosition(position.X +1,position.Y);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		testSprite->SetAnimation(ANIM_LEFT);
		position.SetPosition(position.X - 1, position.Y);

	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		testSprite->SetAnimation(ANIM_FORWARDS);
		position.SetPosition(position.X, position.Y+1);

	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		testSprite->SetAnimation(ANIM_BACKWARDS);
		position.SetPosition(position.X, position.Y -1);

	}
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
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
	}
}

void MainCharacter::RenderSprite()
{
	//------------------------------------------------------------------------
	// Example Sprite Code....
	testSprite->SetPosition(position.X, position.Y);
	testSprite->Draw();
	//------------------------------------------------------------------------
}
