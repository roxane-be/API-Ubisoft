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

	void GetAllEntityLevel(std::list<Entity*>* _list);

	//Entity* mainCharacter = nullptr;
protected:
	GameManager* m_gameManager;
	//std::list<Entity*> m_ButtonEntities;
	//std::list<Entity*> m_EnemiesEntities;

	std::list<Entity*> m_entitiesList;

	float timeWave = 0;
	int currentWave =0;
	void LoadWaves(std::string _pathFolder, std::string _pathFile);
	void LoadEnemy(std::string _pathFolder);
	void LoadNewWave(std::list<Entity*>* _entityList);
	std::list<Wave*> sWaves;
	std::vector<Entity> m_EnemyEntitiesList;

	//split avec un vector enemi, bonus, objetc , (((waves)))..... 
	//std::vector<Entity> m_EnemyEntities;
	//std::vector<Entity> m_BonusEntities;
	//std::vector<Entity> m_ObjectEntities;
	//std::list<Entity*> m_UIEntities;

	
};

