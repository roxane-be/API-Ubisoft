#pragma once

#include <vector>
#include <list>
#include <map>
#include <string>
#include <functional>


class Level;
class Entity;
class MapManager;



class GameManager
{
public:

	enum eStatusGame
	{
		MAINMENU,
		INGAME,
	};

	GameManager();
	void Init();
	void Update(float deltaTime);
	void Render();
	void Shutdown();

	Level* GetLevel() { return m_levels[m_statusGame]; };
	void SetLevel(eStatusGame newLevel);
	eStatusGame GetStatusGame() { return m_statusGame; };
	std::list<Entity*>* GetActiveEntitiesList() { return &m_ActiveEntitiesList; };
	void AddEntityToDelete(Entity* _entity)
	{
		if (std::find(m_EntitiesToDelete.begin(), m_EntitiesToDelete.end(), _entity) == m_EntitiesToDelete.end())
		{
			m_EntitiesToDelete.push_back(_entity);
		}
	};

	void AddEnemyKill() { m_enemiesKilled++; };
	int GetEnemiesKilled() { return m_enemiesKilled; };

	MapManager* ptrMapManager{ nullptr };
	Entity* mainCharacter{ nullptr };

	static GameManager Instance;
	static std::map<std::string, std::function<void()>> functionMap;

private:

	std::vector<Level*> m_levels;
	std::list<Entity*> m_ActiveEntitiesList = std::list<Entity*>();
	std::list<Entity*> m_EntitiesToDelete = std::list<Entity*>();
	int m_enemiesKilled = 0;
	eStatusGame m_statusGame = MAINMENU;
};

