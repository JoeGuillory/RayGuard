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
	//Actor::AddComponent<Sprite>(new Sprite(this, 1));
}

void Enemy::Update(double deltatime)
{
	Actor::Update(deltatime);

}

void Enemy::End()
{
	Actor::End();
}

