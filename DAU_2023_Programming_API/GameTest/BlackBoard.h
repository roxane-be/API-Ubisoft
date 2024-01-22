#pragma once
#include "Component.h"
#include "Collision.h"
#include "AnimationSprite.h"
#include <map>

class BlackBoard : public Component
{
public:

	struct DataCollision
	{
		 std::map<int, const std::vector<Vector2f>*> rectCollisionMap;
		 std::map<int, Collision::eCollisionObjectResponses> typeCollisionMap;
	};

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

	DataCollision dataCollision;

	AnimationSprite::eAnimationSprite currentAnimation = AnimationSprite::eAnimationSprite::TPOSE;

	std::function<void(Entity*)> ptrFOnCollision;
	std::function<void(Entity*)> ptrFOnTrigger;
	std::function<void()> ptrFDeath;
	std::function<void()> ptrFDamage;

private:
	int m_layer{ 0 }; // var Visual Sprite

};

