#include "stdafx.h"
#include "BehaviorPlayer.h"
#include "App/app.h"

void BehaviorPlayer::Init()
{
}

void BehaviorPlayer::Update(float deltaTime)
{
	if (App::IsKeyPressed(VK_TAB) && m_entity->blackBoard->currentAnimation == AnimationSprite::eAnimationSprite::ANIM_WALK)
	{
		m_entity->blackBoard->currentAnimation = AnimationSprite::eAnimationSprite::ANIM_ATTACK;

	}
}

void BehaviorPlayer::Render()
{
}

Component* BehaviorPlayer::Clone(Entity* resultEntity)
{
    return nullptr;
}
