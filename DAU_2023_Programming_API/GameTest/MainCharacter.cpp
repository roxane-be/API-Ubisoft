#include "stdafx.h"
#include "MainCharacter.h"
#include "App/app.h"

MainCharacter::MainCharacter()
{
	
}

void MainCharacter::Init()
{
Character::Init();
}

void MainCharacter::Update(float deltaTime)
{
	Character::Update(deltaTime);
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		sprite.SetAnimation(ANIM_RIGHT);
		transform.SetPosition(transform.GetPosition().x + 1, transform.GetPosition().y);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		sprite.SetAnimation(ANIM_LEFT);
		transform.SetPosition(transform.GetPosition().x - 1, transform.GetPosition().y);

	}
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		sprite.SetAnimation(ANIM_FORWARDS);
		transform.SetPosition(transform.GetPosition().x, transform.GetPosition().y + 1);

	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		sprite.SetAnimation(ANIM_BACKWARDS);
		transform.SetPosition(transform.GetPosition().x, transform.GetPosition().y - 1);

	}
}

void MainCharacter::Render()
{
	Character::Render();
}



//	/*if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP, false))
//	{
//		testSprite->SetScale(testSprite->GetScale() + 0.1f);
//	}
//	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN, false))
//	{
//		testSprite->SetScale(testSprite->GetScale() - 0.1f);
//	}
//	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT, false))
//	{
//		testSprite->SetAngle(testSprite->GetAngle() + 0.1f);
//	}
//	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT, false))
//	{
//		testSprite->SetAngle(testSprite->GetAngle() - 0.1f);
//	}
//	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true))
//	{
//		testSprite->SetAnimation(-1);
//	}*/
//

