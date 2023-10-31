#pragma once


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
	
	float GetPositionX();
	float GetPositionY();
	private: 
	void GetPosition();

	private :
	//SPRITE
	CSimpleSprite* testSprite;
	float posX =0;
	float posY=0;

};

