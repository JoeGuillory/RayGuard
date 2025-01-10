#pragma once
#include "Component.h"
class Shoot : public Component
{
public:

	Shoot(Actor* owner, float firerate);
	~Shoot();

	void Start();
	void Update(double deltaTime);
	void End();
	
	void ShootBullet();
	void SetBulletAngle(float angle) { m_angle = angle; };
	void EnableShoot(bool enable) { m_shootenabled = enable; }
	bool IsEnabled() { return m_shootenabled; }
private:
	float m_fireRate;
	float m_angle;
	double m_time;
	bool m_shootenabled;
};