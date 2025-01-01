#pragma once
#include "Vector2.h"
#include "DynamicArray.h"
#include "Components/Component.h"

class Transform2D;
class Collider;


class Actor
{
public:
	
	Actor(const char* name = nullptr);
	~Actor();

	//Public functions
	static Actor* Instantiate(Actor* actor,Transform2D* parent = nullptr, MathLibrary::Vector2 position = MathLibrary::Vector2(), float rotation = 0);
	void Destroy(Actor* actor);
	virtual void Start();
	virtual void Update(double deltaTime);
	virtual void End();
	virtual void OnEnable() {};
	virtual void OnDisable() {};
	virtual void OnCollision(Actor* other);
	//Getters and Setters
	bool Started() { return m_started; }
	bool Enabled() { return m_enabled; }
	void Enabled(bool value);
	
public:
	template<typename T>
	T* AddComponent(T* component);

	template<typename T>
	T* RemoveComponent(T* component);

	template<typename T>
	T* GetComponent(T* component);


private:

	
	

private:
	bool m_started;
	bool m_enabled;
	const char* m_name;
	DynamicArray<Component*> m_components;
	DynamicArray<Component*> m_componentsToRemove;
public:
	Collider* m_Collider;
	Transform2D* Transform;

	/*Thing that need to be added

	1. Add a collision component and add a OnCollision function 
	*/



};



template<typename T>
inline T* Actor::AddComponent(T* component)
{
	Component* ptr = dynamic_cast<Component*>(component);
	if (ptr == nullptr)
		return nullptr;
	else
	{
		m_components.Add(component);
		return component;
	}
}

template<typename T>
inline T* Actor::RemoveComponent(T* component)
{
	Component* ptr = dynamic_cast<Component*>(component);
	if (ptr == nullptr)
		return false;
	else
	{
		m_componentsToRemove.Add(component);
		return true;
	}
}

template<typename T>
inline T* Actor::GetComponent(T* component)
{
	Component ptr = dynamic_cast<Component>(component);
	if (ptr = nullptr)
		return false;
	else
	{
		for (Component* element : m_components)
		{
			if (element = component)
			{
				return element;
			}
		}
	}
}
