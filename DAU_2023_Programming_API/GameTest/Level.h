#pragma once
#include <list>
#include <functional>

class GameManager;
class Level
{
public:
	Level() = default;
	Level(GameManager* gameManager) {
		m_gameManager = gameManager;
	};

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

	std::list<Entity*> GetButtonEntities() { return m_ButtonEntities; };
	Entity* mainCharacter;
protected:
	GameManager* m_gameManager;
	std::list<Entity*> m_ButtonEntities;
	//split avec un vector enemi, bonus, objetc , (((waves)))..... 
	//std::vector<Entity> m_EnemyEntities;
	//std::vector<Entity> m_BonusEntities;
	//std::vector<Entity> m_ObjectEntities;
	//std::list<Entity*> m_UIEntities;


};

