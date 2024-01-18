#include "stdafx.h"
#include "Collision.h"
#include "App/app.h"
#include "Entity.h"
#include "cassert"

void Collision::Init()
{
}

void Collision::Update(float deltaTime)
{

	for (const auto entity : *GameManager::Instance.GetActiveEntitiesList())
	{

		eCollisionResponses col = collisionPresets[entity->blackBoard->m_typeCollision];
		if (m_entity == entity || entity->blackBoard->m_typeCollision == NONE
			|| col == IGNORECOLLISION)
		{
			continue;
		}
		else
		{
			if (isColliding(entity))
			{
				//assert(false);
			}
		}
	}

}

void Collision::Render()
{
	Vector2f machin = GetSizeCollision();
	machin;

	Vector2f pos = *m_entity->GetTransform()->GetPosition();
	App::DrawLine(pos.x + m_points[0].x, pos.y + m_points[0].y, pos.x + m_points[1].x, pos.y + m_points[1].y, 1, 0, 0);
	App::DrawLine(pos.x + m_points[1].x, pos.y + m_points[1].y, pos.x + m_points[2].x, pos.y + m_points[2].y, 1, 1, 0);
	App::DrawLine(pos.x + m_points[2].x, pos.y + m_points[2].y, pos.x + m_points[3].x, pos.y + m_points[3].y, 1, 0, 1);
	App::DrawLine(pos.x + m_points[3].x, pos.y + m_points[3].y, pos.x + m_points[0].x, pos.y + m_points[0].y, 0, 1, 1);
}

Component* Collision::Clone(Entity* resultEntity)
{
	Collision* collision = new Collision();

	//*collision = *this;
	collision->m_points = this->m_points;
	collision->m_typeCollision = this->m_typeCollision;
	collision->collisionPresets = this->collisionPresets;

	collision->m_entity = resultEntity;
	collision->m_entity->blackBoard = resultEntity->blackBoard;
	collision->m_entity->blackBoard->rectCollision = &m_points;
	collision->m_entity->blackBoard->m_typeCollision = collision->m_typeCollision;

	return collision;
}

bool Collision::isColliding(Entity* other)
{
	if (CollisionCenter(RIGHT, other) > CollisionCenter(LEFT, m_entity)
		&& CollisionCenter(LEFT, other) < CollisionCenter(RIGHT, m_entity))
		return true;


	return false;
}

float Collision::CollisionCenter(eCollisionOutside toCenter, Entity* _entity)
{

	switch (toCenter)
	{
	case Collision::LEFT:
		return _entity->blackBoard->rectCollision->at(0).x + _entity->GetTransform()->GetPosition()->x;

		break;
	case Collision::RIGHT:
		return _entity->blackBoard->rectCollision->at(1).x + _entity->GetTransform()->GetPosition()->x;
		break;
	case Collision::UP:
		assert(false);
		break;
	case Collision::DOWN:
		assert(false);
		break;
	}



	return 0.0f;
}
