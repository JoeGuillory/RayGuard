#include "GameManager.h"
GameManager::GameManager()
{
	m_money = 20;
	m_playerHealth = 10;
}

GameManager::~GameManager()
{
}

void GameManager::Reset()
{
	m_money = 20;
	m_playerHealth = 10;
}
