#include "stdafx.h"
#include "MainCharacter.h"
#include "App/app.h"

MainCharacter::MainCharacter()
{
	transform = Transform(Vector2f(150, 300), Vector2f(0, 0), Vector2f(1, 1));
	entity = Entity(this, 3, entity.GetDamage());
}

void MainCharacter::Init()
{
	Character::Init();
	sprite.CreateSprite(".\\TestData\\Player\\spritesheet.png", 8, 1, 1.0f, ".\\TestData\\Player\\spritesheet.txt");
	if (!sprite.IsNull())
	sprite.SetAnimation(ANIM_WALK);

}

void MainCharacter::Update(float deltaTime)
{
	Character::Update(deltaTime);
	//sprite.SetAnimation(ANIM_WALK);

	//if (App::GetController().GetLeftThumbStickX() > 0.5f)
	//{
	//	sprite.SetAnimation(ANIM_RIGHT);
	//	transform.SetPosition(transform.GetPosition().x + 1, transform.GetPosition().y);
	//}
	//if (App::GetController().GetLeftThumbStickX() < -0.5f)
	//{
	//	sprite.SetAnimation(ANIM_LEFT);
	//	transform.SetPosition(transform.GetPosition().x - 1, transform.GetPosition().y);
	//
	//}
	//if (App::GetController().GetLeftThumbStickY() > 0.5f)
	//{
	//	sprite.SetAnimation(ANIM_FORWARDS);
	//	transform.SetPosition(transform.GetPosition().x, transform.GetPosition().y + 1);
	//
	//}
	//if (App::GetController().GetLeftThumbStickY() < -0.5f)
	//{
	//	sprite.SetAnimation(ANIM_BACKWARDS);
	//	transform.SetPosition(transform.GetPosition().x, transform.GetPosition().y - 1);
	//
	//}
}

void MainCharacter::Render()
{
	Character::Render();

	//for print rect like collision
	{
		float r = 0.0f;
		float g = 1.0f;
		float b = 0.0f;
		int decalage = 55;

		//colplayer
		App::DrawLine(transform.GetPosition().x - decalage, transform.GetPosition().y - decalage * 2, transform.GetPosition().x + decalage, transform.GetPosition().y - decalage * 2, r, g, b);
		App::DrawLine(transform.GetPosition().x + decalage, transform.GetPosition().y - decalage * 2, transform.GetPosition().x + decalage, transform.GetPosition().y + decalage * 2, r, g, b);
		App::DrawLine(transform.GetPosition().x + decalage, transform.GetPosition().y + decalage * 2, transform.GetPosition().x - decalage, transform.GetPosition().y + decalage * 2, r, g, b);
		App::DrawLine(transform.GetPosition().x - decalage, transform.GetPosition().y + decalage * 2, transform.GetPosition().x - decalage, transform.GetPosition().y - decalage * 2, r, g, b);
	}
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

