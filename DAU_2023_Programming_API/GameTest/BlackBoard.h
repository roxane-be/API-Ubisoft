#pragma once
#include "Component.h"
#include "Collision.h"
#include "AnimationSprite.h"
class BlackBoard : public Component
{
public:
	BlackBoard() = default;
	BlackBoard(Entity* parent) : Component(parent) {};

	//method
	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;

	virtual Component* Clone(Entity* resultEntity) override;

	void SetLayerVisualSprite(int _layer) { m_layer = _layer; };
	int GetLayervisualSprite() { return m_layer; };

	Vector2f sizeSprite;
	float scaleSprite{ 1 };

	const std::vector<Vector2f>* rectCollision ;

	Collision::eCollisionObjectResponses m_typeCollision;

	AnimationSprite::eAnimationSprite currentAnimation = AnimationSprite::eAnimationSprite::TPOSE;
	//AnimationSprite::eAnimationSprite currentAnimation = AnimationSprite::eAnimationSprite::TPOSE;

private:
	int m_layer {0}; // var Visual Sprite

};

