#include "Scene.h"
#include "Engine/Actor.h"


Scene::Scene()
{
	
}

Scene::~Scene()
{
	
}

void Scene::AddActor(Actor* actor)
{
	if (!m_actors.Contains(actor))
		m_actors.Add(actor);
}

bool Scene::RemoveActor(Actor* actor)
{
	if(!m_actorsToBeRemoved.Contains(actor))
		m_actorsToBeRemoved.Add(actor);
	return true;
}

void Scene::Start()
{
}

void Scene::Update(double deltaTime)
{
	for (Actor* element : m_actors)
	{
		if (!element->Started())
			element->Start();

		element->Update(deltaTime);
		//Add Collider updating after impleminting colliders
	}


	m_actors.Remove(m_actorsToBeRemoved);
}

void Scene::End()
{
	for (Actor* element : m_actors)
		element->End();
}
