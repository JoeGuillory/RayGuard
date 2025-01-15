#include "Base.h"
#include "Engine/GameManager.h"
#include "Enemy.h"
#include "Engine/Components/Sprite.h"
#include "Engine/Transform2D.h"
#include "Engine/Collider/CircleCollider.h"
#include "Game.h"
#include "Engine/Scene/Scene.h"
#include "Engine/GameManager.h"
Base::Base()
{
	m_scale = 45;
}

Base::~Base()
{
}

void Base::Start()
{
	Actor::Start();
	Sprite* m_sprite = Actor::AddComponent<Sprite>(new Sprite(this, 12));
	m_sprite->SetBothScaler(m_scale);
	m_sprite->SetOffset({ m_scale / 2,m_scale / 2 });
	m_Collider = new CircleCollider(this, 25);
	dynamic_cast<CircleCollider*>(m_Collider)->EnableDraw(true);
	Transform->Translate(25, 220);
}

void Base::Update(double deltatime)
{
	Actor::Update(deltatime);

	
}

void Base::OnCollision(Actor* other)
{
	if (dynamic_cast<Enemy*>(other) != nullptr)
	{
		
		Game::instance->GetCurrentScene()->RemoveActor(other);
		GameManager::instance->SubstractPlayerHealth(25);
		
	}
}

void Base::End()
{
	Actor::End();
	
}
