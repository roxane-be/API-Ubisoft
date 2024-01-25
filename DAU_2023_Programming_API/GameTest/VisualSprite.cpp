#include "stdafx.h"
#include "VisualSprite.h"
#include "App/app.h"
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "App/SimpleSprite.h"

std::map< std::string, const char* > VisualSprite::m_stringFile;


VisualSprite::~VisualSprite()
{
	delete m_sprite;
}

void VisualSprite::CreateSprite(const char* fileName, int columns, int rows, float scale, int layer)
{
	if (!std::filesystem::exists(fileName)
		|| !std::filesystem::is_regular_file(fileName))
		return;

	m_fileName = fileName;
	m_sprite = App::CreateSprite(fileName, columns, rows);
	m_sprite->SetPosition(0.f, 0.f);
	SetScaleSprite(scale);
	m_layer = layer;
}


Vector2f VisualSprite::GetSize()
{
	if (!IsNull())
		return Vector2f(m_sprite->GetWidth(), m_sprite->GetHeight());
	return Vector2f();
}

float VisualSprite::GetScale()
{
	if (!IsNull())
		return m_sprite->GetScale();
	return -1;
}

bool VisualSprite::IsNull()
{
	return (m_sprite == nullptr);
}

void VisualSprite::SetScaleSprite(float scale)
{
	if (!IsNull())
		m_sprite->SetScale(scale);
}

void VisualSprite::Init()
{
}

void VisualSprite::Update(float deltaTime)
{
	if (!IsNull())
		m_sprite->Update(deltaTime / 0.001f);
}

void VisualSprite::Render()
{
	if (!IsNull())
	{
		m_sprite->SetPosition(m_entity->GetTransform()->GetPosition()->x + m_offsetSpritePosition.x, m_entity->GetTransform()->GetPosition()->y + m_offsetSpritePosition.y);
		m_sprite->Draw();
	}
}


Component* VisualSprite::Clone(Entity* resultEntity)
{
	VisualSprite* visualSprite = new VisualSprite();

	*visualSprite = *this;
	visualSprite->m_sprite = App::CreateSprite(m_fileName, 1, 1);
	*(visualSprite->m_sprite) = *(this->m_sprite);

	visualSprite->m_entity = resultEntity;
	visualSprite->m_entity->blackBoard = resultEntity->blackBoard;
	visualSprite->m_entity->blackBoard->sizeSprite = resultEntity->blackBoard->sizeSprite;
	visualSprite->m_entity->blackBoard->currentAnimation = m_entity->blackBoard->currentAnimation;
	visualSprite->m_entity->blackBoard->layerSprite =m_layer;

	// no need because the auto copy is ok for now (and lack some clone func in CSimpleSprite we can't change)
	//visualSprite->CreateSprite(m_fileName, columns, rows, sprite->GetScale, m_layer, line);

	return visualSprite;
}
