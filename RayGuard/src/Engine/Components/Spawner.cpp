#include "Spawner.h"
#include "Component.h"
#include "Engine/Actor.h"
#include "Game/Enemy.h"
#include "Engine/Transform2D.h"
Spawner::Spawner()
{
	m_time = 0;
}

Spawner::~Spawner()
{
}

void Spawner::Start()
{
	
	
}

void Spawner::Update(double deltaTime)
{
	m_time += 1 * deltaTime;
	if (m_time > 6)
	{
		Actor::Instantiate(new Enemy(), nullptr, _owner->Transform->GlobalPosition());
	}
}

void Spawner::End()
{
}
