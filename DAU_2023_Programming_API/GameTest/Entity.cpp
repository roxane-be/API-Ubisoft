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
			else if (line == "AnimationSprite")
			{
				LoadComponentAnimationSprite(*entity, myFile);
			}
			else if (line == "BehaviorAI")
			{
				LoadComponentBehaviorAI(*entity, myFile);
			}
			else if (line == "BehaviorPlayer")
			{
				LoadComponentBehaviorPlayer(*entity, myFile);
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
	BehaviorAI* component = new BehaviorAI(&_entity);
	_entity.blackBoard->ptrFOnCollision = std::bind(&BehaviorAI::OnCollision, component, std::placeholders::_1);
	_entity.blackBoard->ptrFOnTrigger = std::bind(&BehaviorAI::OnTrigger, component, std::placeholders::_1);
	_entity.blackBoard->ptrFDeath = std::bind(&BehaviorAI::Death, component);
	_entity.blackBoard->ptrFDamage = std::bind(&BehaviorAI::Damage, component);
	_entity.AddComponent(component);
}

void Entity::LoadComponentBehaviorPlayer(Entity& _entity, std::ifstream& myFile)
{
	BehaviorPlayer* component = new BehaviorPlayer(&_entity);
	_entity.blackBoard->ptrFOnCollision = std::bind(&BehaviorPlayer::OnCollision, component, std::placeholders::_1);
	_entity.blackBoard->ptrFOnTrigger = std::bind(&BehaviorPlayer::OnTrigger, component, std::placeholders::_1);
	_entity.blackBoard->ptrFDeath = std::bind(&BehaviorPlayer::Death, component);
	_entity.blackBoard->ptrFDamage = std::bind(&BehaviorPlayer::Damage, component);
	_entity.AddComponent(component);
}

void Entity::LoadComponentButton(Entity& _entity, std::ifstream& myFile)
{
	std::string line;

	Button* component = new Button(&_entity);
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
	myFile >> line;
	int columns = std::stoi(line);
	myFile >> line;
	int rows = std::stoi(line);
	myFile >> line;
	float scale = std::stof(line);
	myFile >> line;
	int layer = std::stoi(line);

	VisualSprite* component = new VisualSprite(&_entity);
	component->CreateSprite(pathSprite.c_str(), columns, rows, scale, layer);
	_entity.blackBoard->layerSprite=layer;
	_entity.blackBoard->sizeSprite = component->GetSize();
	_entity.AddComponent(component);
}

void Entity::LoadComponentAnimationSprite(Entity& _entity, std::ifstream& myFile)
{
	std::string line;
	myFile >> line;
	std::string pathSprite = line;
	myFile >> line;
	int columns = std::stoi(line);
	myFile >> line;
	int rows = std::stoi(line);
	myFile >> line;
	float scale = std::stof(line);
	myFile >> line;
	int layer = std::stoi(line);

	AnimationSprite* component = new AnimationSprite(&_entity);
	myFile >> line;
	component->CreateAnimations(pathSprite.c_str(), columns, rows, line, scale, layer);
	component->SetAnimation(AnimationSprite::eAnimationSprite::ANIM_WALK);
	_entity.blackBoard->currentAnimation = AnimationSprite::eAnimationSprite::ANIM_WALK;
	_entity.blackBoard->layerSprite = layer;
	_entity.AddComponent(component);
}

void Entity::LoadComponentCollision(Entity& _entity, std::ifstream& myFile)
{
	Collision* component = new Collision(&_entity);
	std::string line;
	myFile >> line;
	auto typeCollision = FunctionLibrary::ConvertStringToEnumCollisionObjectResponses(line);
	component->SetTypeCollision(typeCollision);

	for (int i = 0; i < 4; i++)
	{
		myFile >> line;
		float x = std::stof(line);
		myFile >> line;
		float y = std::stof(line);
		component->AddPointRectCollision(Vector2f(x, y));
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
	_entity.blackBoard->dataCollision.typeCollisionMap[(int)_entity.blackBoard->dataCollision.rectCollisionMap.size()] = component->GetTypeCollision();
	_entity.blackBoard->dataCollision.rectCollisionMap[(int)_entity.blackBoard->dataCollision.rectCollisionMap.size()] = component->GetRectCollision();
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
	_entity.m_transform.SetPosition(x, y);
	BlackBoard* blackBoard = new BlackBoard(&_entity);
	_entity.blackBoard = blackBoard;
}

void Entity::AddComponent(Component* component)
{
	m_components.push_back(component);
}
