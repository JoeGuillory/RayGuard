#include "Actor.h"
#include "Transform2D.h"

Actor::Actor()
{
	transform = new Transform2D();
	m_started = false;
	m_enabled = true;
	m_name = 0;
}

Actor::Actor(char* name)
{
	m_name = name;
}

Actor::~Actor()
{
	delete transform;
}



Actor Actor::Instantiate(Actor actor, Transform2D* parent, MathLibrary::Vector2 position, float rotation)
{
	actor.transform->LocalPosition(position);
	actor.transform->Rotate(rotation);
	if (parent != nullptr)
		parent->AddChild(actor.transform);
	//add add actor to scene one scenes are implimented
	return actor;
}

void Actor::Destroy()
{
	//destroy all the children in the actors transform
}

void Actor::Start()
{
	m_started = true;
}

void Actor::Update(double deltaTime)
{
	// Update every component
}

void Actor::End()
{
	// End each component
}

void Actor::Enabled(bool value)
{
	if (m_enabled == value)
		return;
	m_enabled = value;
	if (m_enabled)
		OnEnable();
	else
		OnDisable();
}
