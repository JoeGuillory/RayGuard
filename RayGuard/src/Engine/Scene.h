#pragma once

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

private:
	Actor** m_actors;
};