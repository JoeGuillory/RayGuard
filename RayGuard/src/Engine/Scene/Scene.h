#pragma once
#include "DynamicArray.h"

class Actor;

class Scene
{
public:
	Scene();
	~Scene();

	void AddActor(Actor* actor);
	bool RemoveActor(Actor* actor);
	virtual void Start();
	virtual void Update(double deltaTime);
	virtual void End();
	virtual void DrawTiles();

protected:
	DynamicArray<Actor*> m_actors;
	DynamicArray<Actor*> m_actorsToBeRemoved;
};