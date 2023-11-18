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
		std::string stringFile = ".\\TestData\\Map\\Map";
		stringFile += std::to_string(i);
		stringFile += ".png";
		stringFile += "\0";

		char* charFile = new char[stringFile.length() + 1];
		std::strcpy(charFile, stringFile.c_str());

		CSimpleSprite* temp = App::CreateSprite(charFile, 1, 1);
		temp->SetScale(0.8f);
		transform.SetPosition(temp->GetWidth() / 2 * temp->GetScale(), temp->GetHeight() / 2 * temp->GetScale());
		//position.SetPosition(temp->GetWidth() / 2 * temp->GetScale(), temp->GetHeight() / 2 * temp->GetScale());
		temp->SetPosition(transform.GetPosition().x, transform.GetPosition().y);
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
	transform.SetPosition(transform.GetPosition().x + sideScroll, transform.GetPosition().y);
	if (transform.GetPosition().x <= -currentMapShow[0].GetWidth()*currentMapShow[0].GetScale()/2)
	{
		//CSimpleSprite temp = currentMapShow[0];
		currentMapShow[0]= currentMapShow[1];
		currentMapShow[1] = spritesMap[rand() % spritesMap.size()];

		transform.SetPosition(currentMapShow[0].GetWidth() / 2 * currentMapShow[0].GetScale(), currentMapShow[0].GetHeight() / 2 * currentMapShow[0].GetScale());
	}
}

void MapManager::Render()
{
	currentMapShow[0].SetPosition(transform.GetPosition().x, transform.GetPosition().y);
	currentMapShow[0].Draw();
	currentMapShow[1].SetPosition(transform.GetPosition().x + (currentMapShow[0].GetWidth() * currentMapShow[0].GetScale()), transform.GetPosition().y);
	currentMapShow[1].Draw();
}
