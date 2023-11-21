#include "stdafx.h"
#include "Item.h"

Item::Item(int boostLife, float boostCoins, float boostSpeedAttack, float boostTimeShield, int damage)
{
	m_boostLife = boostLife;
	m_boostCoins = boostCoins;
	m_boostSpeedAttack = boostSpeedAttack;
	m_boostTimeShield = boostTimeShield;
	m_damage = damage;
}

int Item::GetBoostLife()
{
	return m_boostLife;
}

float Item::GetBoostCoins()
{
	return m_boostCoins;
}

float Item::GetBoostSpeedAttack()
{
	return m_boostSpeedAttack;
}

float Item::GetBoostTimeShield()
{
	return m_boostTimeShield;
}

int Item::GetDamage()
{
	return m_damage;
}
