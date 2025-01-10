#include "SpawnManager.h"
#include "Engine/Actor.h"
#include "Engine/Components/Spawner.h"
#include "Engine/Transform2D.h"
#include "raylib.h"

SpawnManager::SpawnManager()
{
}

SpawnManager::~SpawnManager()
{
}

void SpawnManager::Start()
{
	Actor::Start();
	AddComponent<Spawner>(new Spawner(this));
	

}

void SpawnManager::Update(double deltaTime)
{
	Actor::Update(deltaTime);
	DrawCircleLines(Transform->GlobalPosition().x, Transform->GlobalPosition().y, 20, BLACK);
	
}

void SpawnManager::End()
{
	Actor::End();

}
