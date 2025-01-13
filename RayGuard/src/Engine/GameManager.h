#pragma once

class GameManager
{
public:
	GameManager();
	~GameManager();

	void Reset();
	float GetMoney() { return m_money; }
	void SubstractMoney(float money) { m_money = m_money - money; }
	void AddMoney(float money) { m_money = m_money + money; }
	float GetTowerCost() { return m_towerCost; }
	float GetPlayerHealth() { return m_playerHealth; }
	void SubstractPlayerHealth(float damage) { m_playerHealth = m_playerHealth - damage; }
	float AddPlayerHealth(float heal) { m_playerHealth = m_playerHealth+ heal; }
	static GameManager* instance;
private:
	float m_money;
	float m_playerHealth;
	float m_towerCost;
};