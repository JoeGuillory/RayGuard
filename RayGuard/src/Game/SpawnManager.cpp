#include "SpawnManager.h"
#include "Engine/Actor.h"
#include "Engine/Components/Spawner.h"
#include "Engine/Transform2D.h"
#include "Game/Button.h"
#include "raylib.h"

SpawnManager::SpawnManager(int maxrounds)
{
	m_maxRounds = maxrounds;
	m_round = 1;
	m_roundSpawnCount = 10;
	m_allCompleted = false;
}

SpawnManager::~SpawnManager()
{
}

void SpawnManager::Start()
{
	Actor::Start();
	m_spawner = AddComponent<Spawner>(new Spawner(this,m_roundSpawnCount));
}

void SpawnManager::Update(double deltaTime)
{
	Actor::Update(deltaTime);
	if (m_round != m_maxRounds)
	{
		if (m_spawner->Finished())
		{
			DrawText("Press Enter to Continue", GetScreenWidth() / 25 , 10, 60, BLACK);
			if (IsKeyDown(KEY_ENTER))
			{
				m_round++;
				m_spawner->SetSpawnCount(m_roundSpawnCount + (m_round * 5));
				m_spawner->Restart();
			}
		}
	}
	else if (m_round == m_maxRounds)
	{
		m_allCompleted = true;
	}

	
}

void SpawnManager::End()
{
	Actor::End();

}

bool SpawnManager::IsRoundFinished()
{
	return m_spawner->Finished();
}
