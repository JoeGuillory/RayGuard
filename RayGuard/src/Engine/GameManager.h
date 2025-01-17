#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Reset();
	float GetMoney() { return m_gold; }
	void SubstractMoney(float money) { m_gold = m_gold - money; }
	void AddMoney(float money) { m_gold = m_gold + money; }
	float GetTowerCost() { return m_towerCost; }
	float GetPlayerHealth() { return m_playerHealth; }
	float GetEnemyHealth() { return m_enemyBaseHealth; }
	void SubstractPlayerHealth(float damage) { m_playerHealth = m_playerHealth - damage; }
	float AddPlayerHealth(float heal) { m_playerHealth = m_playerHealth+ heal; }
	float GetBulletDamage() { return m_bulletDamage; }
	float GetAmountOnKill() { return m_amountOnKill; }
	static GameManager* instance;
private:
	float m_gold;
	float m_playerHealth;
	float m_bulletDamage;
	float m_towerCost;
	float m_enemyBaseHealth;
	float m_amountOnKill;
};