#pragma once
class Entity;
class BlackBoard;
class Component
{
public:
	Component() = default;
	Component(Entity* parent) : m_entity(parent) {}
	~Component() 
	{
		delete m_entity;
		delete m_blackBoard;
	}
	//method
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Shutdown();
	
	const Entity* GetEntity() const { return m_entity; };

protected:
	Entity* m_entity = nullptr;
	BlackBoard* m_blackBoard = nullptr;
};

