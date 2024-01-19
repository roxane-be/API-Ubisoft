#include "stdafx.h"
#include "VisualSprite.h"
#include "App/app.h"
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

std::map< std::string, const char* > VisualSprite::m_stringFile;


void VisualSprite::CreateSprite(const char* fileName, int columns, int rows, float scale, int layer)
{
	if (!std::filesystem::exists(fileName)
		|| !std::filesystem::is_regular_file(fileName))
		return;

	m_fileName = fileName;
	sprite = App::CreateSprite(fileName, columns, rows);
	sprite->SetPosition(0.f, 0.f);
	SetScaleSprite(scale);

	m_layer = layer;
}


Vector2f VisualSprite::GetSize()
{
	if (!IsNull())
		return Vector2f(sprite->GetWidth(), sprite->GetHeight());
	return Vector2f();
}

float VisualSprite::GetScale()
{
	if (!IsNull())
		return sprite->GetScale();
	return -1;
}

bool VisualSprite::IsNull()
{
	return (sprite == nullptr);
}

void VisualSprite::SetScaleSprite(float scale)
{
	if (!IsNull())
		sprite->SetScale(scale);
}



void VisualSprite::Init()
{
}

void VisualSprite::Update(float deltaTime)
{
	if (!IsNull())
		sprite->Update(deltaTime / 0.001);

}

void VisualSprite::Render()
{
	if (!IsNull())
	{
		sprite->SetPosition(m_entity->GetTransform()->GetPosition()->x + m_offsetSpritePosition.x, m_entity->GetTransform()->GetPosition()->y + m_offsetSpritePosition.y);
		sprite->Draw();
	}
}


Component* VisualSprite::Clone(Entity* resultEntity)
{
	VisualSprite* visualSprite = new VisualSprite();

	*visualSprite = *this;
	visualSprite->sprite = App::CreateSprite(m_fileName, 1, 1);
	*(visualSprite->sprite) = *(this->sprite);

	visualSprite->m_entity = resultEntity;
	visualSprite->m_entity->blackBoard = resultEntity->blackBoard;
	visualSprite->m_entity->blackBoard->currentAnimation = m_entity->blackBoard->currentAnimation;
	visualSprite->m_entity->blackBoard->SetLayerVisualSprite(m_layer);

	// no need because the auto copy is ok for now (and lack some clone func in CSimpleSprite we can't change)
	//visualSprite->CreateSprite(m_fileName, columns, rows, sprite->GetScale, m_layer, line);


	return visualSprite;
}
