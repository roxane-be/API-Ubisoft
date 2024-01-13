#pragma once
#include <fstream>

class Component;
class Entity
{
public:
	Entity(std::string name = "") : m_name(name) {};
	Entity(const Entity& other)
	{
		transform = other.transform;
		m_name = other.m_name;
		m_components = other.m_components;
		blackBoard = other.blackBoard;
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

	void Load(Entity* entity, std::string pathFile);
protected:
	void LoadComponentBehavior(Entity& _entity, std::ifstream& myFile);
	void LoadComponentButton(Entity& _entity, std::ifstream& myFile);
	void LoadComponentVisualSprite(Entity& _entity, std::ifstream& myFile);
	void LoadComponentVisualSpriteAndAnimation(Entity& _entity, std::ifstream& myFile);
	//load name entity, this position et create blackboard
	void LoadEntity(Entity& _entity, std::ifstream& myFile);


private:
	Transform transform = Transform();
	std::string m_name;

	std::list<Component*> m_components;
	//Component* componentStatus; // shortcut for perfo
};


