#include "stdafx.h"
#include "LevelMenu.h"
#include <filesystem>

void LevelMenu::Init()
{
	const std::string pathFile = ".\\TestData\\LoadEntities\\LevelMenu";

	for (const auto& entry : std::filesystem::directory_iterator(pathFile))
	{
		if (entry.is_regular_file())
		{
			Entity* entity = new Entity();
			entity->Load(entity, entry.path().string());
			m_ButtonEntities.push_back(entity);
		}
	}
}

void LevelMenu::Update(float deltaTime)
{

}

void LevelMenu::Render()
{

}

