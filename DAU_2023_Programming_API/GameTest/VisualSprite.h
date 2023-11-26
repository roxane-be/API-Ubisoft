#pragma once
#include "Component.h"

class CSimpleSprite;

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
private:
	void CreateAnimations(const char* fileNameAnimation);
	CSimpleSprite* sprite = nullptr;



};


