#include "stdafx.h"
#include "BehaviorPlayer.h"
#include "App/app.h"
#include "cassert"

void BehaviorPlayer::Init()
{
}

void BehaviorPlayer::Update(float deltaTime)
{
	if (!doOnceAttack && App::IsKeyPressed(VK_TAB) && m_entity->blackBoard->currentAnimation == AnimationSprite::eAnimationSprite::ANIM_WALK)
	{
		m_entity->blackBoard->currentAnimation = AnimationSprite::eAnimationSprite::ANIM_ATTACK;
		doOnceAttack = true;
	}
	if (doOnceAttack)
	{
		timingAttack -= deltaTime;
		if (timingAttack <= 0)
		{
			timingAttack = TIMING_ATTACK;
			doOnceAttack = false;
		}
	}
}

void BehaviorPlayer::Render()
{
}

void BehaviorPlayer::OnCollision(Entity* other)
{
	if (m_entity->blackBoard->currentAnimation == AnimationSprite::eAnimationSprite::ANIM_ATTACK
		&& doOnceAttack)
	{
		other->blackBoard->ptrFDamage();
	}
	//Damage();
}

void BehaviorPlayer::Damage()
{
	m_entity->GetTransform()->SetPosition(m_entity->GetTransform()->GetPosition()->x - 200.f, m_entity->GetTransform()->GetPosition()->y);
	OutsideScreen();
}

void BehaviorPlayer::Death()
{
	GameManager::Instance.SetLevel(MainMenu);
}

Component* BehaviorPlayer::Clone(Entity* resultEntity)
{
	assert(false);
	return nullptr;
}

void BehaviorPlayer::OutsideScreen()
{
	if (m_entity->GetTransform()->GetPosition()->x <= 0)
	{
		m_entity->GetTransform()->SetPosition(APP_VIRTUAL_WIDTH / 2, m_entity->GetTransform()->GetPosition()->y);
		m_entity->blackBoard->currentAnimation = AnimationSprite::eAnimationSprite::ANIM_DEATH;
	}
}
