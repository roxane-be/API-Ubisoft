#pragma once
#include "Component.h"
class BlackBoard : public Component
{
public:
	BlackBoard() = default;
	BlackBoard(Entity* parent) : Component(parent) {};

	//method
	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	void SetLayerVisualSprite(int _layer) { m_layer = _layer; };
	int GetLayervisualSprite() { return m_layer; };

	Vector2f sizeSprite;
	float scaleSprite{ 1 };

private:
	int m_layer {0}; // var Visual Sprite

};
