#include "stdafx.h"
#include "MapManager.h"
#include "App/app.h"
#include "App/SimpleSprite.h"
#include <string>
#include <ctime>  
MapManager::MapManager()
{
}

void MapManager::Init()
{
	for (int i = 0; i < 5; i++)
	{
		std::string stringFile = ".\\TestData\\Map\\Map";
		stringFile += std::to_string(i);
		stringFile += ".png";
		stringFile += "\0";

		char* charFile = new char[stringFile.length() + 1];
		std::strcpy(charFile, stringFile.c_str());

		spritesMap.push_back(VisualSprite());
		spritesMap[spritesMap.size()-1].CreateSprite(charFile, 1, 1, 0.8f);

	}
	transform.SetPosition(spritesMap[0].GetSize().x / 2 * spritesMap[0].GetScale(), spritesMap[0].GetSize().y / 2 * spritesMap[0].GetScale());
	srand(time(0));
	currentMapShow.push_back(spritesMap[rand() % spritesMap.size()]);
	currentMapShow.push_back(spritesMap[rand() % spritesMap.size()]);
}

void MapManager::Update(float deltaTime)
{
	transform.SetPosition(transform.GetPosition().x + sideScroll, transform.GetPosition().y);
	if (transform.GetPosition().x <= -currentMapShow[0].GetSize().x * currentMapShow[0].GetScale() / 2)
	{
		currentMapShow[0] = currentMapShow[1];
		currentMapShow[1] = spritesMap[rand() % spritesMap.size()];

		transform.SetPosition(currentMapShow[0].GetSize().x / 2 * currentMapShow[0].GetScale(), currentMapShow[0].GetSize().y / 2 * currentMapShow[0].GetScale());
	}
}

void MapManager::Render()
{
	currentMapShow[0].RenderSprite(Vector2f(transform.GetPosition().x, transform.GetPosition().y));
	currentMapShow[1].RenderSprite(Vector2f(transform.GetPosition().x + (currentMapShow[0].GetSize().x * currentMapShow[0].GetScale()), transform.GetPosition().y));

}
