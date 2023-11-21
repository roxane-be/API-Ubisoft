#pragma once

class CSimpleSprite;

class VisualSprite
{
public:
	VisualSprite();

	void CreateSprite(const char* fileName, int columns, int rows, float scale = 1.0f,
		const char* fileNameAnimation = "None\0");
	void SetScaleSprite(float scale);
	void SetAnimation(int id);
	void Update(float deltaTime);
	void RenderSprite(Vector2f& position);
	Vector2f GetSize();
	float GetScale();
	bool IsNull();
private:
	void CreateAnimations(const char* fileNameAnimation);
	CSimpleSprite* sprite = nullptr;



};


