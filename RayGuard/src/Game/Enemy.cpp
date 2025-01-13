#include "Enemy.h"
#include "Engine/Components/Sprite.h"
#include "Engine/Transform2D.h"
#include "Engine/Collider/CircleCollider.h"
#include "Bullet.h"
#include "Game.h"
#include "Engine/Scene/Scene.h"
#include <iostream>
#include "Engine/GameManager.h"

Enemy::Enemy()
{
	m_scale = 60;
	health = 100.0f;
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
	m_Collider = new CircleCollider(this, 25);
	dynamic_cast<CircleCollider*>(m_Collider)->EnableDraw(true);
	
}

void Enemy::Update(double deltatime)
{
	Actor::Update(deltatime);
	dynamic_cast<CircleCollider*>(m_Collider)->Draw();
	Transform->Translate(Transform->GetForward() * deltatime * -200);
	
}


void Enemy::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
	{
		Game::instance->GetCurrentScene()->RemoveActor(this);
		Game::instance->GetCurrentScene()->RemoveActor(other);
		GameManager::instance->AddMoney(5);
	}
}

void Enemy::End()
{
	Actor::End();
}

