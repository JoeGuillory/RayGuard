#include "Actor.h"
#include "Transform2D.h"

Actor::Actor(const char* name)
{
	Transform = new Transform2D();
	m_started = false;
	m_enabled = true;
	m_name = name;
}

Actor::~Actor()
{
	delete Transform;
}



Actor Actor::Instantiate(Actor actor, Transform2D* parent, MathLibrary::Vector2 position, float rotation)
{
	actor.Transform->LocalPosition(position);
	actor.Transform->Rotate(rotation);
	if (parent != nullptr)
		parent->AddChild(actor.Transform);
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
