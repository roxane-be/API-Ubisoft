#pragma once
#include <list>
#include <functional>

class GameManager;
class Level
{

public : 
public:
	struct Wave
	{
		float time;
		std::list <std::string> pathEnemyToLoad;
	};
public:
	Level() = default;
	Level(GameManager* gameManager = nullptr) : m_gameManager(gameManager){};

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void Shutdown();

	void GetAllEntitiesLevel(std::list<Entity*>* _list);

	void LoadEntities(std::string _pathFile);

protected:
	GameManager* m_gameManager;

	std::list<Entity*> m_entitiesList;

	float timeWave = 0;
	int currentWave =0;
	void LoadWaves(std::string _pathFolder, std::string _pathFile);
	void LoadEnemies(std::string _pathFolder);
	void LoadNewWave(std::list<Entity*>* _entityList);

	std::list<Wave*> sWaves;
	std::map< std::string, Entity* > m_EnemyEntitiesMap;

	bool playerIsDead =false;
	
};

