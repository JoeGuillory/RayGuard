#include "Tower.h"
#include "Engine/Components/Sprite.h"
#include "Engine/Actor.h"

Tower::Tower()
{
	
}

Tower::~Tower()
{
}

void Tower::Start()
{
	Actor::Start();
	m_sprite = AddComponent<Sprite>(new Sprite(this, 1));
	m_sprite->SetBothScaler(35);
}

void Tower::Update(double deltaTime)
{
	Actor::Update(deltaTime);
}

void Tower::End()
{
	Actor::End();
}
