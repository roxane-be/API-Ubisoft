#pragma once
#include <fstream>
#include "BlackBoard.h"

class Component;
class Entity
{
public:
	enum eTypeCollision
	{
		None,
		MainCharacter,
		EnemyGround,
	};
	
public:
	Entity(std::string name = "", eTypeCollision typeCollision = None) : m_name(name), m_typeCollision(typeCollision) {};
	Entity(const Entity& other)
	{
		transform = other.transform;
		m_name = other.m_name + std::string(" Cloned");
		m_typeCollision = other.m_typeCollision;

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
	Transform* GetTransform() { return &transform; }
	const std::list<Component*> GetComponents() { return m_components; };
	BlackBoard* blackBoard = nullptr;

	eTypeCollision GetTypeCollision() {return m_typeCollision;};

	void Load(Entity* entity, std::string pathFile);
protected:
	void LoadComponentBehavior(Entity& _entity, std::ifstream& myFile);
	void LoadComponentButton(Entity& _entity, std::ifstream& myFile);
	void LoadComponentVisualSprite(Entity& _entity, std::ifstream& myFile);
	void LoadComponentVisualSpriteAndAnimation(Entity& _entity, std::ifstream& myFile);
	void LoadComponentCollision(Entity& _entity, std::ifstream& myFile);
	//load name entity, this position et create blackboard
	void LoadEntity(Entity& _entity, std::ifstream& myFile);


private:
	Transform transform = Transform();
	std::string m_name;
	eTypeCollision m_typeCollision;

	std::list<Component*> m_components;
	//Component* componentStatus; // shortcut for perfo
};


