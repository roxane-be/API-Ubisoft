#pragma once

class Component;
class Entity
{
public:
	Entity() = default;
	Entity(const char* name) : m_name(name) {};

	~Entity()
	{
		delete m_name;
		delete blackBoard;
		//for (auto it = m_components.begin(); it != m_components.end();)
		//{
		//	delete* it;
		//	it = m_components.erase(it);
		//}

	}
	// To Character
	//Entity(Character* owner, int life = 1, int damage =1);
	//void TakeDamage(int damageToTake);
	//void Death();
	//Character* GetOwner();
	//int GetLife();
	//int GetDamage();

	void Init();
	void Update(float deltaTime);
	void Render();
	void Shutdown();

	void AddComponent(Component* component);
	Transform* GetTransform() { return &transform; }
	const std::list<Component*> GetComponents() { return m_components; };
	BlackBoard* blackBoard = nullptr;

private:
	Transform transform = Transform();
	const char* m_name = "None";
	// To Character
	//int m_life = 1;
	//int m_damage = 1;
	//Character* m_owner;
	std::list<Component*> m_components;
	//Component* componentStatus; // shortcut for perfo
};


