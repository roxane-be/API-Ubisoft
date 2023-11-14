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
	for (int i = 0; i<5; i++)
	{
		std::string file = ".\\TestData\\Map\\Map";
		file += std::to_string(i);
		file += ".bmp";
		CSimpleSprite* temp = App::CreateSprite(file.c_str(), 1, 1);
		temp->SetScale(0.8f);
		position.SetPosition(temp->GetWidth() / 2 * temp->GetScale(), temp->GetHeight() / 2 * temp->GetScale());
		temp->SetPosition(position.X, position.Y);
		spritesMap.push_back(*temp);
		temp = nullptr;

	}
	srand(time(0));
	srand(time(0));
	currentMapShow.push_back(spritesMap[rand() % spritesMap.size()]);
	currentMapShow.push_back(spritesMap[rand() % spritesMap.size()]);
}

void MapManager::Update(float deltaTime)
{
	position.SetPosition(position.X + sideScroll, position.Y);
	if (position.X <= -currentMapShow[0].GetWidth()*currentMapShow[0].GetScale()/2)
	{
		//CSimpleSprite temp = currentMapShow[0];
		currentMapShow[0]= currentMapShow[1];
		currentMapShow[1] = spritesMap[rand() % spritesMap.size()];

		position.SetPosition(currentMapShow[0].GetWidth() / 2 * currentMapShow[0].GetScale(), currentMapShow[0].GetHeight() / 2 * currentMapShow[0].GetScale());
	}
}

void MapManager::Render()
{
	currentMapShow[0].SetPosition(position.X, position.Y);
	currentMapShow[0].Draw();
	currentMapShow[1].SetPosition(position.X + (currentMapShow[0].GetWidth() * currentMapShow[0].GetScale()), position.Y);
	currentMapShow[1].Draw();
}
