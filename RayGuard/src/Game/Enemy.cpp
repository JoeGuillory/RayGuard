#include "Enemy.h"
#include "Engine/Components/Sprite.h"

Enemy::Enemy(const char* name) : Actor::Actor(name)
{
	
}

Enemy::~Enemy()
{
	
}

void Enemy::Start()
{
	Actor::Start();
	Sprite* m_sprite = Actor::AddComponent<Sprite>(new Sprite(this, 1));
	m_sprite->SetBothScaler(100);
}

void Enemy::Update(double deltatime)
{
	Actor::Update(deltatime);

}

void Enemy::End()
{
	Actor::End();
}

