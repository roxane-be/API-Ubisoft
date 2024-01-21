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
		&& !doOnceAttack)
	{
		other->blackBoard->ptrFDamage();
		doOnceAttack = true;
	}
}

void BehaviorPlayer::Damage()
{
}

void BehaviorPlayer::Death()
{
}

Component* BehaviorPlayer::Clone(Entity* resultEntity)
{
	assert(false);
	return nullptr;
}
