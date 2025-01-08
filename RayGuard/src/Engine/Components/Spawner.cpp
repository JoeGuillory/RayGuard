#include "Spawner.h"
#include "Component.h"
#include "Engine/Actor.h"
#include "Game/Enemy.h"
#include "Engine/Transform2D.h"
#include "raylib.h"
#include <string>
#include <iostream>
Spawner::Spawner(Actor* owner) : Component::Component(owner)
{
	m_time = 0;
}

void Spawner::Start()
{
	
	
}

void Spawner::Update(double deltaTime)
{
	m_time += 1.000 * deltaTime;
	//std::cout << m_time << std::endl;
	if (m_time > 5)
	{
		Actor::Instantiate(new Enemy(), nullptr, _owner->Transform->GlobalPosition());
		
		m_time = 0;
		

	}
}

void Spawner::End()
{
}
