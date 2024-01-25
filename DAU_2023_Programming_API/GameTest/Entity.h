#pragma once
#include <fstream>
#include "BlackBoard.h"
#include "Collision.h"

class Component;
class Entity
{
public:
	Entity(std::string name = "") : m_name(name) {};
	Entity(const Entity& other)
	{
		m_transform = other.m_transform;
		m_name = other.m_name + std::string(" Cloned");

		blackBoard = static_cast<BlackBoard*>(other.blackBoard->Clone(this));  // copy

		for (const auto component : other.m_components)
		{
			Component* newComponent = component->Clone(this);  // copy
			m_components.push_back(newComponent);
		}
	}

	~Entity()
	{
		for (auto component : m_components)
		{
			delete component;
		}
		m_components.clear();
		delete blackBoard;
	}

	void Init();
	void Update(float deltaTime);
	void Render();
	void Shutdown();


	void AddComponent(Component* component);
	Transform* GetTransform() { return &m_transform; }
	const std::list<Component*> GetComponents() { return m_components; };
	BlackBoard* blackBoard = nullptr;


	void Load(Entity* entity, std::string pathFile);
protected:
	//no information in file 
	void LoadComponentBehaviorAI(Entity& _entity, std::ifstream& myFile);
	//no information in file 
	void LoadComponentBehaviorPlayer(Entity& _entity, std::ifstream& myFile);
	//load text button, offset text, ptr function for OnClick
	void LoadComponentButton(Entity& _entity, std::ifstream& myFile);
	//load path sprite, columns, rows, scale, layer
	void LoadComponentVisualSprite(Entity& _entity, std::ifstream& myFile);
	//load path sprite, columns, rows, scale, layer, path spritsheet text
	void LoadComponentAnimationSprite(Entity& _entity, std::ifstream& myFile);
	//load typeCollision, 4 point for rectCollision, collisionPreset
	void LoadComponentCollision(Entity& _entity, std::ifstream& myFile);
	//Load name, position 
	void LoadEntity(Entity& _entity, std::ifstream& myFile);


private:
	Transform m_transform = Transform();
	std::string m_name;
	std::list<Component*> m_components;
};


