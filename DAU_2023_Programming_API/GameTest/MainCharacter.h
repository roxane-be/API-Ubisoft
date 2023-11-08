#pragma once
#include "Entity.h"

class CSimpleSprite;
enum AnimationSprite
{
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT
};

class MainCharacter : public Entity
{
public:
	MainCharacter();
	~MainCharacter() { delete testSprite; };

	//SPRITE
	void InitSprite();
	void UpdateSprite(float deltaTime);
	void RenderSprite();

	
	private :
	//SPRITE
	CSimpleSprite* testSprite ;

};

