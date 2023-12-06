#pragma once
class Entity;
class BlackBoard;
class Component
{
public:
	Component(Entity* parent = nullptr, BlackBoard* blackBoard = nullptr) : m_entity(parent), m_blackBoard(blackBoard) {}

	//method
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;

	const Entity* GetEntity() const { return m_entity; };

protected:
	Entity* m_entity;
	BlackBoard* m_blackBoard;
};

