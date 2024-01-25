#pragma once
#include <list>
#include <functional>

class GameManager;
class Level
{
public:

public:
	Level(){};

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Shutdown();

	void GetAllEntitiesLevel(std::list<Entity*>* _list);

	void LoadEntities(std::string _pathFile);

protected:

	struct Wave
	{
		float time;
		std::list <std::string> pathEnemyToLoad;
	};

	void LoadWaves(std::string _pathFolder, std::string _pathFile);
	void LoadEnemies(std::string _pathFolder);
	void LoadNewWave(std::list<Entity*>* _entityList);

	std::list<Entity*> m_entitiesList;

	float m_timeWave = 0;
	int m_currentWave = 0;

	std::list<Wave*> m_sWaves;
	std::map< std::string, Entity* > m_EnemyEntitiesMap;

	bool m_playerIsDead = false;

};

