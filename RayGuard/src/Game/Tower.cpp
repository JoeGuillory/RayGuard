#include "Tower.h"
#include "Engine/Components/Sprite.h"
#include "Engine/Actor.h"
#include "Engine/Collider/CircleCollider.h"
#include "raylib.h"
#include "Engine/Transform2D.h"
#include "Game/Enemy.h"
#include "Bullet.h"
#include <cmath>


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
	m_sprite->SetOffset({ 35 / 2,35 / 2 });
	m_Collider = new CircleCollider(this, 150);
	dynamic_cast<CircleCollider*>(m_Collider)->EnableDraw(true);
}

void Tower::Update(double deltaTime)
{
	Actor::Update(deltaTime);
	m_Collider->Draw();
	
}

void Tower::End()
{
	Actor::End();
}

void Tower::OnCollision(Actor* other)
{
	if (dynamic_cast<Enemy*>(other) != nullptr)
	{

		float enemyangle = atan2(other->Transform->GlobalPosition().x - Transform->GlobalPosition().x, other->Transform->GlobalPosition().y - Transform->GlobalPosition().y);

		Actor::Instantiate(new Bullet(), nullptr, Transform->GlobalPosition(), enemyangle * 180 / PI);
	}

}
