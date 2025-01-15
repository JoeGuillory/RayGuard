#include "GameManager.h"
GameManager* GameManager::instance = nullptr;
GameManager::GameManager()
{
	if (instance == nullptr)
		instance = this;
	m_money = 20;
	m_playerHealth = 100;
	m_enemyBaseHealth = 100;
	m_towerCost = 10;
	m_bulletDamage = 25;
	m_amountOnKill = 5;
}

GameManager::~GameManager()
{
}

void GameManager::Reset()
{
	m_money = 20;
	m_playerHealth = 100;
	
	
}
