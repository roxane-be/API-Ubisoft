#pragma once

class Component;
class Entity
{
public:
	Entity() = default;
	Entity(const char* name) : m_name(name) {};

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

private:
	Transform transform = Transform();
	const char* m_name = "None";

	std::list<Component*> m_components;
	//Component* componentStatus; // shortcut for perfo
};


