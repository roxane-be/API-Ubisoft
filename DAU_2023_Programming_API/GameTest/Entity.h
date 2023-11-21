#pragma once

class Character;
class Entity
{
public:
	Entity();
	Entity(Character* owner, int life = 1, int damage =1);
	void TakeDamage(int damageToTake);
	void Death();
	Character* GetOwner();
	int GetLife();
	int GetDamage();

private:
	int m_life = 1;
	int m_damage = 1;
	Character* m_owner;
};

