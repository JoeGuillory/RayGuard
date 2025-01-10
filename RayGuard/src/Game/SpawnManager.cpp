#include "SpawnManager.h"
#include "Engine/Actor.h"
#include "Engine/Components/Spawner.h"
#include "Engine/Transform2D.h"
#include "raylib.h"

SpawnManager::SpawnManager()
{
	m_round = 1;
	m_roundSpawnCount = 10;
}

SpawnManager::~SpawnManager()
{
}

void SpawnManager::Start()
{
	Actor::Start();
	AddComponent<Spawner>(new Spawner(this,m_roundSpawnCount));
	

}

void SpawnManager::Update(double deltaTime)
{
	Actor::Update(deltaTime);
	
}

void SpawnManager::End()
{
	Actor::End();

}
