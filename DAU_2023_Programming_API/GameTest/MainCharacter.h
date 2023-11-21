#pragma once
#include "Character.h"
#include "Transform.h"
#include "VisualSprite.h"

class CSimpleSprite;
enum AnimationSprite
{
	ANIM_WALK=0,
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT
};

class MainCharacter : public Character
{
public:
	MainCharacter();
	~MainCharacter() { /*delete testSprite;*/ };


	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;

};

