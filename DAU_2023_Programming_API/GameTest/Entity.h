#pragma once

class MainCharacter;
class Entity
{
public:
	Entity(MainCharacter* owner);
	void TakeDamage(int damageToTake);
	void Death();
	MainCharacter* GetOwner();

private:
	int m_life = 1;
	int m_damage = 0;
	MainCharacter* m_owner;
};

