#pragma once
#include "Component.h"

class CSimpleSprite;
class BlackBoard;
enum eAnimationSprite
{
	ANIM_WALK=0,
};

class VisualSprite : public Component
{
public:
	VisualSprite();
	VisualSprite(Entity* parent, BlackBoard* _blackBoard)
	{
		m_entity = parent;
		m_blackBoard = _blackBoard;
	};

	void CreateSprite(const char* fileName, int columns, int rows, float scale = 1.0f, int layer =0,
		const char* fileNameAnimation = "None\0");
	void SetScaleSprite(float scale);
	void SetAnimation(int id);

	virtual void Update(float deltaTime);
	virtual void Render();
	Vector2f GetSize();
	float GetScale();
	bool IsNull();

	Vector2f* GetOffsetSpritePosition() {return &m_offsetSpritePosition;};

	void SetLayer(int _layer) { m_layer = _layer; };
	int GetLayer() { return m_layer; };

private:
	void CreateAnimations(const char* fileNameAnimation);
	CSimpleSprite* sprite = nullptr;
	Vector2f m_offsetSpritePosition = Vector2f();
	//le Z, fond
	int m_layer =0;



};


