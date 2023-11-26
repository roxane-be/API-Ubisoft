#include "stdafx.h"
#include "VisualSprite.h"
#include "App/app.h"
#include "App/SimpleSprite.h"
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

VisualSprite::VisualSprite()
{
	sprite = nullptr;
}

VisualSprite::VisualSprite(Entity* parent)
{
	m_entity = parent;
}

void VisualSprite::CreateSprite(const char* fileName, int columns, int rows, float scale,
	const char* fileNameAnimation)
{
	if (!std::filesystem::exists(fileName)
		|| !std::filesystem::is_regular_file(fileName))
		return;


	sprite = App::CreateSprite(fileName, columns, rows);
	sprite->SetPosition(0.f, 0.f);
	SetScaleSprite(scale);


	if (fileNameAnimation != "None")
	{
		CreateAnimations(fileNameAnimation);
	}

}

void VisualSprite::CreateAnimations(const char* fileNameAnimation)
{
	std::ifstream myFile(fileNameAnimation);

	std::vector <std::vector<int>> tabAnim;
	float speed;
	if (myFile)
	{
		myFile >> speed;
		std::string line;
		int count = 0;

		while (!myFile.eof()) {
			tabAnim.push_back(std::vector<int>(0, 0));
			myFile >> line;
			int enumAnim = line[0] - '0';
			myFile >> line;
			int frameBegin = std::stoi(line);
			myFile >> line;
			int frameEnd = std::stoi(line);
			for (int i = frameBegin; i != frameEnd + 1; i++)
			{
				tabAnim[count].push_back(i);
			}
			count++;
		}
	}
	for (int i = 0; i < tabAnim.size(); i++)
		sprite->CreateAnimation(i, speed, tabAnim[i]);

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

void VisualSprite::SetAnimation(int id)
{
	if (!IsNull())
		sprite->SetAnimation(id);
}

void VisualSprite::Update(float deltaTime)
{
	if (!IsNull())
		sprite->Update(deltaTime);
}

void VisualSprite::Render()
{
	if (!IsNull())
	{
		sprite->SetPosition(m_entity->GetTransform()->GetPosition()->x + m_offsetSpritePosition.x, m_entity->GetTransform()->GetPosition()->y + m_offsetSpritePosition.y);
		sprite->Draw();
	}
}
