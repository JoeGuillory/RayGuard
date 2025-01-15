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
	m_enemyHealth = GameManager::instance->GetEnemyHealth();
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
	
	if (m_enemyHealth <= 0)
	{
		GameManager::instance->AddMoney(GameManager::instance->GetAmountOnKill());
		Game::instance->GetCurrentScene()->RemoveActor(this);
	}
}


void Enemy::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other) != nullptr)
	{
		m_enemyHealth -= GameManager::instance->GetBulletDamage();
		Game::instance->GetCurrentScene()->RemoveActor(other);
	}
}

void Enemy::End()
{
	Actor::End();
}

