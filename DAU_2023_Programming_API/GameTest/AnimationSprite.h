#pragma once
#include "VisualSprite.h"

class AnimationSprite : public VisualSprite
{
public:
	enum eAnimationSprite
	{
		ANIM_WALK,
		ANIM_ATTACK,
		ANIM_DEATH,
		TPOSE,
	};

	AnimationSprite(Entity* parent = nullptr) : VisualSprite(parent) {};


	virtual void Update(float deltaTime) override;

	virtual Component* Clone(Entity* resultEntity) override;

	void CreateAnimations(const char* fileName, int columns, int rows, std::string fileNameAnimation, float scale = 1.0f, int layer = 0);

	void SetAnimation(eAnimationSprite id);

	unsigned int GetFrame()  const;

protected:

	std::map< eAnimationSprite, bool> m_animationLoopingMap;
	std::map< eAnimationSprite, int> m_lastFrameMap;

	eAnimationSprite currentAnimation = TPOSE;

};

