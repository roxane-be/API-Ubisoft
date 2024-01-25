#pragma once
#include "Component.h"


class CSimpleSprite;
class BlackBoard;

class VisualSprite : public Component
{
public:
	VisualSprite(Entity* parent = nullptr) : Component(parent) {};
	~VisualSprite();

	//override pure function parent 
	virtual void Init() override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;
	virtual Component* Clone(Entity* resultEntity) override;

	void CreateSprite(const char* fileName, int columns, int rows, float scale = 1.0f, int layer = 0);
	void SetScaleSprite(float scale);

	Vector2f GetSize();
	float GetScale();
	bool IsNull();

	Vector2f* GetOffsetSpritePosition() { return &m_offsetSpritePosition; };

	void SetLayer(int _layer) { m_layer = _layer; };
	int GetLayer() { return m_layer; };

protected:

	std::string m_fileName="";
	CSimpleSprite* m_sprite{ nullptr };
	Vector2f m_offsetSpritePosition = Vector2f();
	int m_layer = 0;
};


