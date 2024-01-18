#include "stdafx.h"
#include "Entity.h"
#include <fstream>
#include <string>
#include <functional>
#include <sstream>
#include <iostream>
#include <map>
#include <cassert>

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
				LoadComponentButton(*entity, myFile);
			}
			else if (line == "VisualSprite")
			{
				LoadComponentVisualSprite(*entity, myFile);
			}
			else if (line == "VisualSpriteAndAnimation")
			{
				LoadComponentVisualSpriteAndAnimation(*entity, myFile);
			}
			else if (line == "BehaviorAI")
			{
				LoadComponentBehaviorAI(*entity, myFile);
			}
			else if (line == "Collision")
			{
				LoadComponentCollision(*entity, myFile);
			}
		}

	}
}

void Entity::LoadComponentBehaviorAI(Entity& _entity, std::ifstream& myFile)
{
	BehaviorAI* component = new BehaviorAI(&_entity, _entity.blackBoard);
	_entity.AddComponent(component);
}

void Entity::LoadComponentButton(Entity& _entity, std::ifstream& myFile)
{
	std::string line;


	Button* component = new Button(&_entity, _entity.blackBoard);
	component->Init();
	myFile >> line;
	component->SetText(line);
	myFile >> line;
	float x = std::stof(line);
	myFile >> line;
	float y = std::stof(line);
	component->SetOffsetTextPosition(Vector2f(x, y));

	myFile >> line;
	component->ptrF = GameManager::functionMap[line];
	_entity.AddComponent(component);
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

	VisualSprite* component = new VisualSprite(&_entity, _entity.blackBoard);
	component->CreateSprite(VisualSprite::m_stringFile[VisualSprite::m_stringFile[pathSprite]], columns, rows, layer);
	_entity.blackBoard->SetLayerVisualSprite(layer);
	_entity.AddComponent(component);
}

void Entity::LoadComponentVisualSpriteAndAnimation(Entity& _entity, std::ifstream& myFile)
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
	float scale = std::stof(line);
	myFile >> line;
	float layer = std::stof(line);

	VisualSprite* component = new VisualSprite(&_entity, _entity.blackBoard);
	myFile >> line;
	component->CreateSprite(VisualSprite::m_stringFile[VisualSprite::m_stringFile[pathSprite]], columns, rows, scale, layer, line);
	component->SetAnimation(eAnimationSprite::ANIM_WALK);
	_entity.blackBoard->SetLayerVisualSprite(layer);
	_entity.AddComponent(component);
}

void Entity::LoadComponentCollision(Entity& _entity, std::ifstream& myFile)
{
	Collision* component = new Collision(&_entity, _entity.blackBoard);
	std::string line;
	myFile >> line;
	auto typeCollision = FunctionLibrary::ConvertStringToEnumCollisionObjectResponses(line);
	component->m_typeCollision = typeCollision;

	for (int i = 0; i < 4; i++)
	{
		myFile >> line;
		float x = std::stof(line);
		myFile >> line;
		float y = std::stof(line);
		component->m_points.push_back(Vector2f(x, y));
	}
	for (int i = 0; i < component->collisionPresets.size(); i++)
	{
		myFile >> line;
		auto key = FunctionLibrary::ConvertStringToEnumCollisionObjectResponses(line);
		myFile >> line;
		auto value = FunctionLibrary::ConvertStringToEnumCollisionResponses(line);

		auto it = component->collisionPresets.find(key);

		if (it != component->collisionPresets.end()) {
			component->collisionPresets[key] = value;
		}
		else
			assert(false);

	}
	_entity.blackBoard->m_typeCollision = component->m_typeCollision;
	_entity.blackBoard->rectCollision = &component->m_points;
	_entity.AddComponent(component);
}

void Entity::LoadEntity(Entity& _entity, std::ifstream& myFile)
{
	std::string line;
	myFile >> line;
	std::string name = line;

	_entity = Entity(name);
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
