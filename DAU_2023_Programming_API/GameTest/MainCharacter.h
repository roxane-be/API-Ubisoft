#pragma once
#include "Transform.h"

class CSimpleSprite;
enum AnimationSprite
{
	ANIM_FORWARDS,
	ANIM_BACKWARDS,
	ANIM_LEFT,
	ANIM_RIGHT
};

class MainCharacter 
{
public:
	MainCharacter();
	~MainCharacter() { delete testSprite; };

	//SPRITE
	void InitSprite();
	void UpdateSprite(float deltaTime);
	void RenderSprite();

	Transform transform;
	
	private :
	//SPRITE
	CSimpleSprite* testSprite ;


	//Vector2f other ;

};

