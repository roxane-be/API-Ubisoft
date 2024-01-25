#pragma once
class Entity;

class Component
{
public:
	Component(Entity* parent = nullptr) : m_entity(parent) {}

	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;
	virtual Component* Clone(Entity* resultEntity) = 0;

	const Entity* GetEntity() const { return m_entity; };

protected:
	Entity* m_entity;
};

