#pragma once

static struct GameManager
{
public:
	GameManager();
	~GameManager();

	void Reset();

	float m_money;
	float m_playerHealth;

};