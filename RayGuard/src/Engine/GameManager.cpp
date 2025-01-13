#include "GameManager.h"
GameManager* GameManager::instance = nullptr;
GameManager::GameManager()
{
	if (instance == nullptr)
		instance = this;
	m_money = 20;
	m_playerHealth = 10;
	m_towerCost = 10;
}

GameManager::~GameManager()
{
}

void GameManager::Reset()
{
	m_money = 20;
	m_playerHealth = 10;
	
}
