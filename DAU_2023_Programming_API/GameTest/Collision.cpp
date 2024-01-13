#include "stdafx.h"
#include "Collision.h"
#include "App/app.h"

void Collision::Init()
{
}

void Collision::Update(float deltaTime)
{
}

void Collision::Render()
{
	Vector2f pos = *m_entity->GetTransform()->GetPosition();
	App::DrawLine(pos.x + m_points[0].x, pos.y + m_points[0].y, pos.x + m_points[1].x, pos.y + m_points[1].y, 1, 0, 0);
	App::DrawLine(pos.x + m_points[1].x, pos.y + m_points[1].y, pos.x + m_points[2].x, pos.y + m_points[2].y, 1, 1, 0);
	App::DrawLine(pos.x + m_points[2].x, pos.y + m_points[2].y, pos.x + m_points[3].x, pos.y + m_points[3].y, 1, 0, 1);
	App::DrawLine(pos.x + m_points[3].x, pos.y + m_points[3].y, pos.x + m_points[0].x, pos.y + m_points[0].y, 0, 1, 1);
}
