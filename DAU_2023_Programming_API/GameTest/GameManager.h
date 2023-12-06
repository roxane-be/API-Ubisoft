#pragma once

#include <vector>
#include <list>
#include <map>
#include <string>

class Level;
class Entity;
class MapManager;

enum eCurrentLevel
{
	MainMenu,
	Game,
	Shop,
	numberLevel
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
	eCurrentLevel currentLevel = MainMenu;
	eCurrentLevel oldLevel = MainMenu;
	std::list<Entity*>* GetActiveEntity() { return &m_ActiveEntityList; };
	void SetLevel(eCurrentLevel newLevel);

	MapManager* ptrMapManager{nullptr};
private:

	static std::map<const char*, std::string > m_stringFile;
	std::vector<Level*> m_levels;
	std::list<Entity*> m_ActiveEntityList =  std::list<Entity *>();

};

