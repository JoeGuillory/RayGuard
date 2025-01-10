#include "Shoot.h"
#include "Engine/Actor.h"
#include "Game/Bullet.h"
#include "Engine/Transform2D.h"

Shoot::Shoot(Actor* owner,float firerate) : Component::Component(owner)
{

	m_fireRate = firerate;
	m_shootenabled = false;
}

Shoot::~Shoot()
{
}

void Shoot::Start()
{
}

void Shoot::Update(double deltaTime)
{

	if (m_shootenabled)
	{
		m_time += 1 * deltaTime;

		if (m_time > m_fireRate / 60)
		{
			ShootBullet();
			m_time = 0;
		}
	}

}

void Shoot::End()
{
}

void Shoot::ShootBullet()
{
	Actor::Instantiate(new Bullet(), nullptr, _owner->Transform->GlobalPosition(), m_angle);
}
