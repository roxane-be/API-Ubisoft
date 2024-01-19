#pragma once
#include "VisualSprite.h"
class CSimpleSprite;


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

	unsigned int GetFrame()  const {return sprite->GetFrame();};

protected:

	eAnimationSprite currentAnimation = TPOSE;

};

