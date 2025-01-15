#include "Engine/Collider/CircleCollider.h"
#include "Engine/Collider/Collider.h"
#include "Engine/Actor.h"
#include "Engine/Transform2D.h"
#include "Bullet.h"
#include "Engine/Components/Sprite.h"
#include "Game.h"
#include "Engine/Scene/Scene.h"

Bullet::Bullet()
{
	m_scale = 150;
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
	Actor::Start();
	Sprite* m_sprite = Actor::AddComponent<Sprite>(new Sprite(this, 11));
	m_sprite->SetBothScaler(m_scale);
	m_sprite->SetOffset({ m_scale / 2,m_scale / 2 });
	m_Collider = new CircleCollider(this, 25);
	dynamic_cast<CircleCollider*>(m_Collider)->EnableDraw(true);
	
}

void Bullet::Update(double deltaTime)
{
	Actor::Update(deltaTime);
	dynamic_cast<CircleCollider*>(m_Collider)->Draw();
	Transform->Translate(Transform->GetForward() * deltaTime * 400);
	
	if (Transform->LocalPosition().x > GetScreenWidth() ||
		(Transform->LocalPosition().y > GetScreenHeight()))
	{
		Game::instance->GetCurrentScene()->RemoveActor(this);
	}
	

}



void Bullet::End()
{
	Actor::End();
}
