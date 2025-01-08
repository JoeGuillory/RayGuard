#include "Enemy.h"
#include "Engine/Components/Sprite.h"
#include "Engine/Transform2D.h"
#include "Engine/Collider/CircleCollider.h"

Enemy::Enemy()
{
	m_scale = 60;
}

Enemy::~Enemy()
{
	
}

void Enemy::Start()
{
	Actor::Start();
	Sprite* m_sprite = Actor::AddComponent<Sprite>(new Sprite(this, 6));
	m_sprite->SetBothScaler(m_scale);
	m_sprite->SetOffset({ m_scale / 2,m_scale / 2 });
	Transform->Translate({ 90,90 });
	m_Collider = new CircleCollider(this, 25);
	dynamic_cast<CircleCollider*>(m_Collider)->EnableDraw(false);
	
}

void Enemy::Update(double deltatime)
{
	Actor::Update(deltatime);
	dynamic_cast<CircleCollider*>(m_Collider)->Draw();
	Transform->Translate(Transform->GetForward() * deltatime * -20);
}

void Enemy::End()
{
	Actor::End();
}

