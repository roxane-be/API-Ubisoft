#pragma once

#include <vector>
#include <list>
#include <map>
#include <string>
#include <functional>


class Level;
class Entity;
class MapManager;

enum eCurrentLevel
{
	MAINMENU,
	GAME,
};


class GameManager
{
public:
	GameManager();
	void Init();
	void Update(float deltaTime);
	void Render();
	void Shutdown();


	Level* GetCurrentLevel() { return m_levels[currentLevel]; };
	eCurrentLevel currentLevel = MAINMENU;
	std::list<Entity*>* GetActiveEntitiesList() { return &m_ActiveEntitiesList; };
	void SetLevel(eCurrentLevel newLevel);
	void AddEntityToDelete(Entity* _entity) { m_EntitiesToDelete.push_back(_entity); };

	void AddEnemyKill() { enemyKill++; };
	MapManager* ptrMapManager{ nullptr };
	Entity* mainCharacter{ nullptr };

	int GetEnemiesKill() { return enemyKill; };

	static GameManager Instance;
	static std::map<std::string, std::function<void()>> functionMap;

private:

	std::vector<Level*> m_levels;
	std::list<Entity*> m_ActiveEntitiesList = std::list<Entity*>();
	std::list<Entity*> m_EntitiesToDelete = std::list<Entity*>();
	int enemyKill = 0;
};

