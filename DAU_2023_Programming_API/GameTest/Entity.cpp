#include "stdafx.h"
#include "Entity.h"
#include <fstream>
#include <string>
#include <functional>
#include <sstream>
#include <iostream>

void Entity::Init()
{
}

void Entity::Update(float deltaTime)
{
	for (const auto component : m_components)
	{
		component->Update(deltaTime);
	}
}

void Entity::Render()
{
	for (const auto component : m_components)
	{
		component->Render();
	}
}

void Entity::Shutdown()
{

}

void Entity::Load(Entity* entity, std::string pathFile)
{

	std::ifstream myFile(pathFile);
	if (myFile)
	{

		std::string line;
		while (!myFile.eof())
		{
			myFile >> line;
			if (line == "Entity")
			{
				LoadEntity(*entity, myFile);
			}
			else if (line == "Button")
			{
				LoadComponentButton(*entity,myFile);
			}
			else if (line == "VisualSprite")
			{
				LoadComponentVisualSprite(*entity, myFile);
			}
		}

	}
}

void Entity::LoadComponentButton(Entity& _entity, std::ifstream& myFile)
{
	std::string line;
	

	Button* componentButtonPlay = new Button(&_entity, _entity.blackBoard);
	componentButtonPlay->Init();
	myFile >> line;
	componentButtonPlay->SetText(line);
	myFile >> line;
	float x = std::stof(line);
	myFile >> line;
	float y = std::stof(line);
	componentButtonPlay->SetOffsetTextPosition(Vector2f(x, y));

	componentButtonPlay->ptrF = []() {exit(0); };
	_entity.AddComponent(componentButtonPlay);
}

void Entity::LoadComponentVisualSprite(Entity& _entity, std::ifstream& myFile)
{
	std::string line;
	myFile >> line;
	std::string pathSprite = line;
	char* charFile = new char[pathSprite.length() + 1];
	std::strcpy(charFile, pathSprite.c_str());
	VisualSprite::m_stringFile[pathSprite] = charFile;
	myFile >> line;
	float columns = std::stof(line);
	myFile >> line;
	float rows = std::stof(line);
	myFile >> line;
	float layer = std::stof(line);

	VisualSprite* componentVisualButtonPlay = new VisualSprite(&_entity, _entity.blackBoard);
	componentVisualButtonPlay->CreateSprite(VisualSprite::m_stringFile[VisualSprite::m_stringFile[pathSprite]], columns, rows, layer);
	_entity.blackBoard->SetLayerVisualSprite(layer);
	_entity.AddComponent(componentVisualButtonPlay);
}

void Entity::LoadEntity(Entity& _entity, std::ifstream& myFile)
{
	std::string line;
	myFile >> line;
	_entity =  Entity(line);
	myFile >> line;
	float x = std::stof(line);
	myFile >> line;
	float y = std::stof(line);
	_entity.transform.SetPosition(x, y);
	BlackBoard* blackBoard = new BlackBoard(&_entity);
	_entity.blackBoard = blackBoard;
}

void Entity::AddComponent(Component* component)
{
	m_components.push_back(component);
}
