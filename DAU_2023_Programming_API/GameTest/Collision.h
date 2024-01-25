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
		ERROR
	};


public:
	Collision(Entity* parent = nullptr) : Component(parent) {};

	//override function pure parent
	virtual void Init() override;
	virtual void Update(float deltaTime)override;
	virtual void Render()override;
	virtual Component* Clone(Entity* resultEntity) override;


	void SetTypeCollision(eCollisionObjectResponses _typeCollision) { m_typeCollision = _typeCollision; };
	eCollisionObjectResponses GetTypeCollision() { return m_typeCollision; };

	void AddPointRectCollision(Vector2f _point) { m_points.push_back(_point); };
	std::vector<Vector2f>* GetRectCollision() { return &m_points; };

	Vector2f GetSizeCollision() { return Vector2f(abs(m_points[0].x) + abs(m_points[1].x), abs(m_points[0].y) + abs(m_points[3].y)); };

	std::map<Collision::eCollisionObjectResponses, Collision::eCollisionResponses> collisionPresets =
	{
		{Collision::eCollisionObjectResponses::MAINCHARACTER , Collision::eCollisionResponses::IGNORECOLLISION},
		{Collision::eCollisionObjectResponses::ENEMYGROUND , Collision::eCollisionResponses::IGNORECOLLISION},
		{Collision::eCollisionObjectResponses::WEAPONS , Collision::eCollisionResponses::IGNORECOLLISION},
	};

private:
	float CollisionCenter(eCollisionOutside toCenter, Vector2f* entityPosition, const std::vector<Vector2f>* _rectCollision);
	bool isColliding(Entity* other, const std::vector<Vector2f>* _rectCollision);

	Collision::eCollisionObjectResponses m_typeCollision = NONE;
	std::vector<Vector2f> m_points;
};

