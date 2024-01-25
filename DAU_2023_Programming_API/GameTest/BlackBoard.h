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

	//override function pure parent Component
	virtual void Init() override;
	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual Component* Clone(Entity* resultEntity) override;


	//Component VisualSprite
	Vector2f sizeSprite;
	float scaleSprite{ 1 };
	int layerSprite{ 0 };
	//Component AnimationSprite
	AnimationSprite::eAnimationSprite currentAnimation = AnimationSprite::eAnimationSprite::TPOSE;
	//Component Collision
	DataCollision dataCollision;
	//Component Behavior 
	std::function<void(Entity*)> ptrFOnCollision;
	std::function<void(Entity*)> ptrFOnTrigger;
	std::function<void()> ptrFDeath;
	std::function<void()> ptrFDamage;


};

