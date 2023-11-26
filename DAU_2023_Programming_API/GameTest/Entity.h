#pragma once

class Component;
class Entity
{
public:
	Entity() = default;
	Entity(const char* name) : m_name(name) {};
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
	
	void AddComponent(Component* component);
	Transform* GetTransform() { return &transform; }

private:
	Transform transform = Transform();
	const char* m_name = "None";
	// To Character
	//int m_life = 1;
	//int m_damage = 1;
	//Character* m_owner;
	std::vector<Component*> m_components;
	//Component* componentStatus; // shortcut for perfo
};


