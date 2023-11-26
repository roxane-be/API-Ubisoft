#pragma once
#include "Component.h"

class CSimpleSprite;

enum eAnimationSprite
{
	ANIM_WALK=0,
};

class VisualSprite : public Component
{
public:
	VisualSprite();
	VisualSprite(Entity* parent);

	void CreateSprite(const char* fileName, int columns, int rows, float scale = 1.0f,
		const char* fileNameAnimation = "None\0");
	void SetScaleSprite(float scale);
	void SetAnimation(int id);

	virtual void Update(float deltaTime);
	virtual void Render();
	Vector2f GetSize();
	float GetScale();
	bool IsNull();

	Vector2f* GetOffsetSpritePosition() {return &m_offsetSpritePosition;};
private:
	void CreateAnimations(const char* fileNameAnimation);
	CSimpleSprite* sprite = nullptr;
	Vector2f m_offsetSpritePosition = Vector2f();



};


