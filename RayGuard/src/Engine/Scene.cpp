#include "Scene.h"

Scene::Scene()
{
	m_actors = new Actor * [0];
}

Scene::~Scene()
{
	delete m_actors;
}

void Scene::AddActor(Actor* actor)
{
}

bool Scene::RemoveActor(Actor* actor)
{
	return false;
}

void Scene::Start()
{
}

void Scene::Update(double deltaTime)
{

}

void Scene::End()
{
	
}
