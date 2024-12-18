#include "Component.h"

Component::Component(Actor* Owner)
{
	_owner = Owner;
	m_enabled = true;
	m_started = false;
}

Component::~Component()
{
}

void Component::Update(double deltaTime)
{
	
		
}

void Component::Enabled(bool value)
{
	// If enabled would not change, do nothing
	if (m_enabled == value) return;
	m_enabled = value;

	// If value is true, call OnEnabled
	if (m_enabled)
		OnEnable();

	// If value is false, call OnDisable
	else OnDisable();
}
