#pragma once
#include "Vector2.h"


class Transform2D;



class Actor
{
public:
	
	Actor(char* name = nullptr);
	~Actor();

	//Public functions
	Actor Instantiate(Actor actor,Transform2D* parent = nullptr, MathLibrary::Vector2 position = MathLibrary::Vector2(), float rotation = 0);
	void Destroy();
	virtual void Start();
	virtual void Update(double deltaTime);
	virtual void End();
	virtual void OnEnable() {};
	virtual void OnDisable() {};

	//Getters and Setters
	bool Started() { return m_started; }
	bool Enabled() { return m_enabled; }
	void Enabled(bool value);

private:
	bool m_started;
	bool m_enabled;
	char* m_name;
public:
	Transform2D* Transform;

	/*Thing that need to be added
	1.AddComponent
	2.RemoveComponent specific one
	3 Remove Component
	4.Get component
	5. Get Mulitple components
	6. Deal with the component list like adding and removing them from the list
	7. Add component variable and array
	8. Add a collision component and add a OnCollision function 
	*/



};