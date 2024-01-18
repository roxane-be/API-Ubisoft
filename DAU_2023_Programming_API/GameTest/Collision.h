#pragma once
#include "Component.h"
#include <math.h>

class Collision : public Component
{

public:

	enum eCollisionOutside
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};

	enum eCollisionObjectResponses
	{
		NONE,
		MAINCHARACTER,
		ENEMYGROUND,
		WEAPONS,
	};
	enum eCollisionResponses
	{
		IGNORECOLLISION,
		OVERLAP,
		BLOCK,
	};
public:
	Collision(Entity* parent = nullptr, BlackBoard* _blackboard = nullptr) : Component(parent, _blackboard) {};

	virtual void Init() override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;

	virtual Component* Clone(Entity* resultEntity) override;


	Vector2f GetSizeCollision()
	{
		return Vector2f(abs(m_points[0].x) + abs(m_points[1].x), abs(m_points[0].y) + abs(m_points[3].y));
	};



public:

	Collision::eCollisionObjectResponses m_typeCollision;

	
	std::map<Collision::eCollisionObjectResponses, Collision::eCollisionResponses> collisionPresets =
	{
		{Collision::eCollisionObjectResponses::MAINCHARACTER , Collision::eCollisionResponses::IGNORECOLLISION},
		{Collision::eCollisionObjectResponses::ENEMYGROUND , Collision::eCollisionResponses::IGNORECOLLISION},
		{Collision::eCollisionObjectResponses::WEAPONS , Collision::eCollisionResponses::IGNORECOLLISION},
	};

	std::vector<Vector2f> m_points;

	float CollisionCenter(eCollisionOutside toCenter, Entity* _entity);
	bool isColliding(Entity* other);
};

