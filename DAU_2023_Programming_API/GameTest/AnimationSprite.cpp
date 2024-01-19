#include "stdafx.h"
#include "AnimationSprite.h"
#include "App/app.h"


void AnimationSprite::Update(float deltaTime)
{
	VisualSprite::Update(deltaTime);
	if (currentAnimation != m_entity->blackBoard->currentAnimation)
		SetAnimation(m_entity->blackBoard->currentAnimation);
}



void AnimationSprite::SetAnimation(eAnimationSprite id)
{
	if (!IsNull())
	{
		sprite->SetAnimation((int)id);
		currentAnimation = id;
		m_entity->blackBoard->currentAnimation = id;
	}
}

void AnimationSprite::CreateAnimations(const char* fileName, int columns, int rows, std::string fileNameAnimation, float scale, int layer)
{

	CreateSprite(fileName, columns, rows, scale, layer);

	std::ifstream myFile(fileNameAnimation);

	std::vector <std::vector<int>> tabAnim;
	float speed = 0;
	if (myFile)
	{
		myFile >> speed;
		std::string line;
		int count = 0;

		while (!myFile.eof()) {
			tabAnim.push_back(std::vector<int>(0, 0));
			myFile >> line;
			myFile >> line;
			int frameBegin = std::stoi(line);
			myFile >> line;
			int frameEnd = std::stoi(line);
			for (int i = frameBegin; i != frameEnd + 1; i++)
			{
				tabAnim[count].push_back(i);
			}
			count++;
		}
	}
	for (int i = 0; i < tabAnim.size(); i++)
		sprite->CreateAnimation(i, speed, tabAnim[i]);
}

Component* AnimationSprite::Clone(Entity* resultEntity)
{
	AnimationSprite* animationSprite = new AnimationSprite();

	*animationSprite = *this;
	animationSprite->sprite = App::CreateSprite(m_fileName, 1, 1);
	*(animationSprite->sprite) = *(this->sprite);

	animationSprite->m_entity = resultEntity;
	animationSprite->m_entity->blackBoard = resultEntity->blackBoard;
	animationSprite->m_entity->blackBoard->currentAnimation = m_entity->blackBoard->currentAnimation;
	animationSprite->m_entity->blackBoard->SetLayerVisualSprite(m_layer);
	animationSprite->currentAnimation = currentAnimation;

	return animationSprite;

}