#include "stdafx.h"
#include "MapManager.h"
#include "App/app.h"
#include "App/SimpleSprite.h"
#include <string>
#include <ctime>  
#include <filesystem>

MapManager::MapManager()
{
}

MapManager::MapManager(Entity* parent)
{
	m_entity = parent;
}

void MapManager::Init()
{

	const std::string pathFile = ".\\TestData\\Map";
	int nbElemenet = 0;

	for (const auto& entry : std::filesystem::directory_iterator(pathFile)) {
		nbElemenet++;
	}

	for (int i = 0; i < nbElemenet; i++)
	{
		std::string stringFile = ".\\TestData\\Map\\Map";
		stringFile += std::to_string(i);
		stringFile += ".png";
		stringFile += "\0";

		char* charFile = new char[stringFile.length() + 1];
		std::strcpy(charFile, stringFile.c_str());

		spritesMap.push_back(VisualSprite(m_entity));
		spritesMap[spritesMap.size() - 1].CreateSprite(charFile, 1, 1, 0.8f);

	}
	m_entity->GetTransform()->SetPosition(spritesMap[0].GetSize().x / 2 * spritesMap[0].GetScale(), spritesMap[0].GetSize().y / 2 * spritesMap[0].GetScale());
	srand(time(0));

	for (int i = 0; i < 2; i++)
	{
		currentMapShow[i] = rand() % spritesMap.size();

	}
}

void MapManager::Update(float deltaTime)
{
	m_entity->GetTransform()->SetPosition(m_entity->GetTransform()->GetPosition()->x + SpeedSideScroll, m_entity->GetTransform()->GetPosition()->y);

	if (m_entity->GetTransform()->GetPosition()->x <= -spritesMap[currentMapShow[0]].GetSize().x * spritesMap[currentMapShow[0]].GetScale() / 2 )
	{
		currentMapShow[0] = currentMapShow[1];
		currentMapShow[1] = rand() % spritesMap.size();
		spritesMap[currentMapShow[0]].GetOffsetSpritePosition()->SetVector2f(0, 0);
		spritesMap[currentMapShow[1]].GetOffsetSpritePosition()->SetVector2f(spritesMap[currentMapShow[0]].GetSize().x * spritesMap[currentMapShow[0]].GetScale(), 0);
		m_entity->GetTransform()->SetPosition(spritesMap[currentMapShow[0]].GetSize().x / 2 * spritesMap[currentMapShow[0]].GetScale(), spritesMap[currentMapShow[0]].GetSize().y / 2 * spritesMap[currentMapShow[0]].GetScale());
	}
}

void MapManager::Render()
{
	spritesMap[currentMapShow[0]].GetOffsetSpritePosition()->SetVector2f(0, 0);
	spritesMap[currentMapShow[0]].Render();
	spritesMap[currentMapShow[1]].GetOffsetSpritePosition()->SetVector2f(spritesMap[currentMapShow[0]].GetSize().x * spritesMap[currentMapShow[0]].GetScale(), 0);
	spritesMap[currentMapShow[1]].Render();
}
