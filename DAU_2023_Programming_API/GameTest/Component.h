#pragma once
class Entity;
class Component
{
public:
	Component() = default;
	Component(Entity* parent) : m_entity(parent) {}
	//method
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

	const Entity* GetEntity() const { return m_entity; };

protected:
	Entity* m_entity;
};

