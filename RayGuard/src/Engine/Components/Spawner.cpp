#include "Spawner.h"
#include "Component.h"
#include "Engine/Actor.h"
#include "Game/Enemy.h"
#include "Engine/Transform2D.h"
#include "raylib.h"
#include <string>
#include <iostream>
Spawner::Spawner(Actor* owner, int spawncount) : Component::Component(owner)
{
	m_time = 0;
	m_spawncount = spawncount;
	m_spawned = 0;
}

void Spawner::Start()
{
	
	
}

void Spawner::Update(double deltaTime)
{
	m_time += 1.000 * deltaTime;
	
	if (m_time > 5)
	{
		if (m_spawned < m_spawncount)
		{
			Actor::Instantiate(new Enemy(), nullptr, _owner->Transform->GlobalPosition());
			m_spawned++;
		}
		
		m_time = 0;
	}
}

void Spawner::End()
{
}
