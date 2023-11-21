#pragma once
class Item
{
public:
	Item(int boostLife =0, float boostCoins =0 , float boostSpeedAttack =0,
		float boostTimeShield =0, int damage =0 );

	int GetBoostLife();
	float GetBoostCoins();
	float GetBoostSpeedAttack();
	float GetBoostTimeShield();
	int GetDamage();

protected:
	int m_boostLife =0;
	float m_boostCoins =0;
	float m_boostSpeedAttack=0;
	float m_boostTimeShield =0;
	int m_damage =0;

};

