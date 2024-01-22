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
		for (int i = 0; i < entity->blackBoard->dataCollision.typeCollisionMap.size(); i++)
		{

			eCollisionResponses col = collisionPresets[entity->blackBoard->dataCollision.typeCollisionMap.at(i)];
			if (m_entity == entity || entity->blackBoard->dataCollision.typeCollisionMap.at(i) == NONE
				|| col == IGNORECOLLISION)
			{
				continue;
			}
			else
			{
				if (col == BLOCK && isColliding(entity, entity->blackBoard->dataCollision.rectCollisionMap[i]))
				{
					m_entity->blackBoard->ptrFOnCollision(entity);
					return;
				}
				else if (col == OVERLAP && isColliding(entity, entity->blackBoard->dataCollision.rectCollisionMap[i]))
				{
					m_entity->blackBoard->ptrFOnTrigger(entity);
					return;
				}

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
	collision->m_entity->blackBoard->dataCollision.rectCollisionMap[collision->m_entity->blackBoard->dataCollision.rectCollisionMap.size()] = &m_points;
	collision->m_entity->blackBoard->dataCollision.typeCollisionMap[collision->m_entity->blackBoard->dataCollision.typeCollisionMap.size()] = collision->m_typeCollision;

	return collision;
}

bool Collision::isColliding(Entity* other, const std::vector<Vector2f>* _rectCollision)
{
	if (CollisionCenter(RIGHT, other->GetTransform()->GetPosition(), _rectCollision) > CollisionCenter(LEFT, m_entity->GetTransform()->GetPosition(), &m_points)
		&& CollisionCenter(LEFT, other->GetTransform()->GetPosition(), _rectCollision) < CollisionCenter(RIGHT, m_entity->GetTransform()->GetPosition(), &m_points))
		return true;


	return false;
}

float Collision::CollisionCenter(eCollisionOutside toCenter, Vector2f* entityPosition, const std::vector<Vector2f>* _rectCollision)
{

	switch (toCenter)
	{
	case Collision::LEFT:
		return _rectCollision->at(0).x + +entityPosition->x;

		break;
	case Collision::RIGHT:
		return _rectCollision->at(1).x + +entityPosition->x;

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
