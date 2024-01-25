#include "stdafx.h"
#include "AnimationSprite.h"
#include "App/app.h"
#include "cassert"


void AnimationSprite::Update(float deltaTime)
{
	VisualSprite::Update(deltaTime);

	if (m_currentAnimation != m_entity->blackBoard->currentAnimation)
		SetAnimation(m_entity->blackBoard->currentAnimation);

	else if (!m_animationLoopingMap[m_currentAnimation] && GetFrame() == m_lastFrameMap[m_currentAnimation])
	{
		if (m_currentAnimation == ANIM_DEATH)
		{
			m_entity->blackBoard->ptrFDeath();
		}
		else
			SetAnimation(ANIM_WALK);
	}

}

void AnimationSprite::SetAnimation(eAnimationSprite id)
{
	if (!IsNull())
	{
		m_sprite->SetAnimation((int)id, true);
		m_currentAnimation = id;
		m_entity->blackBoard->currentAnimation = id;
	}
}

unsigned int AnimationSprite::GetFrame() const
{
	return m_sprite->GetFrame();
}


void AnimationSprite::CreateAnimations(const char* fileName, int columns, int rows, std::string fileNameAnimation, float scale, int layer)
{
	CreateSprite(fileName, columns, rows, scale, layer);

	std::ifstream myFile(fileNameAnimation);

	if (myFile)
	{
		

		while (!myFile.eof())
		{
			std::string line;
			std::vector <int> tabAnim;
			float speed;
			myFile >> line;
			AnimationSprite::eAnimationSprite animEnum = FunctionLibrary::ConvertStringToEnumAnimationSprite(line);
			myFile >> speed;
			myFile >> line;
			int frameBegin = std::stoi(line);
			int frameEnd;/* = std::stoi(line);*/
			myFile >> frameEnd;
			for (int i = frameBegin; i != frameEnd + 1; i++)
			{
				tabAnim.push_back(i);
			}
			m_sprite->CreateAnimation((int)animEnum, speed, tabAnim);
			myFile >> line;
			m_animationLoopingMap[animEnum] = FunctionLibrary::ConvertStringToBoolean(line);
			m_lastFrameMap[animEnum] = frameEnd;

		}
	}
}

Component* AnimationSprite::Clone(Entity* resultEntity)
{
	AnimationSprite* animationSprite = new AnimationSprite();

	*animationSprite = *this;
	animationSprite->m_sprite = App::CreateSprite(m_fileName.c_str(), 1, 1);
	*(animationSprite->m_sprite) = *(this->m_sprite);

	animationSprite->m_entity = resultEntity;
	animationSprite->m_entity->blackBoard = resultEntity->blackBoard;
	animationSprite->m_entity->blackBoard->currentAnimation = ANIM_WALK;
	animationSprite->m_entity->blackBoard->layerSprite = m_layer;
	animationSprite->m_currentAnimation = ANIM_WALK;
	animationSprite->m_animationLoopingMap = m_animationLoopingMap;
	animationSprite->m_lastFrameMap = m_lastFrameMap;

	return animationSprite;

}