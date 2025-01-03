#include "Actor.h"
#include "Transform2D.h"
#include "Components\Component.h"
#include "Game.h"
#include "Scene/Scene.h"


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



Actor* Actor::Instantiate(Actor* actor, Transform2D* parent, MathLibrary::Vector2 position, float rotation)
{
	actor->Transform->LocalPosition(position);
	actor->Transform->Rotate(rotation);
	if (parent != nullptr)
		parent->AddChild(actor->Transform);
	Game::GetCurrentScene()->AddActor(actor);
	//add add actor to scene one scenes are implimented
	return actor;
}

void Actor::Destroy(Actor* actor)
{
	for (Transform2D* element : actor->Transform->GetChildren())
	{
		actor->Transform->RemoveChild(element);
	}
	if (actor->Transform->GetParent() != nullptr)
	{
		actor->Transform->GetParent()->RemoveChild(actor->Transform);
	}
}

void Actor::Start()
{
	m_started = true;
}

void Actor::Update(double deltaTime)
{
	for (Component* element : m_components)
	{
		if (!element->Started())
			element->Start();
		
		element->Update(deltaTime);
	}
	m_components.Remove(m_componentsToRemove);
}

void Actor::End()
{
	for (Component* element : m_components)
	{
		element->End();
	}
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

