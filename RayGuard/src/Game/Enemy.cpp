#include "Enemy.h"

Enemy::Enemy(const char* name) : Actor::Actor(name)
{
	
}

Enemy::~Enemy()
{
	
}

void Enemy::Start()
{
	Actor::Start();

}

void Enemy::Update(double deltatime)
{
	Actor::Update(deltatime);

}

void Enemy::End()
{
	Actor::End();
}

