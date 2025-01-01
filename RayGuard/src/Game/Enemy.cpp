#include "Enemy.h"
#include "Engine/Components/Sprite.h"
#include "Engine/Transform2D.h"

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
	m_sprite->SetBothScaler(15);
	m_sprite->SetTextureWidth(m_sprite->GetTextureWidth() / 3);
	Transform->Translate({ 90,90 });

}

void Enemy::Update(double deltatime)
{
	Actor::Update(deltatime);
	
}

void Enemy::End()
{
	Actor::End();
}

