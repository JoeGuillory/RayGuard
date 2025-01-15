#include "Scene.h"
#include "Engine/Actor.h"
#include "Engine/Collider/Collider.h"

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
	for (int i = 0; i < m_actors.Length(); i++)
	{
		if (!m_actors[i]->Started())
			m_actors[i]->Start();

		m_actors[i]->Update(deltaTime);

	}

	for (int row = 0; row < m_actors.Length(); row++)
	{
		for (int column = row; column < m_actors.Length(); column++)
		{
			if (row == column)
				continue;
			if (m_actors[row]->m_Collider != nullptr && m_actors[column]->m_Collider != nullptr)
			{
				if (m_actors[row]->m_Collider->CheckCollision(m_actors[column]))
				{
					m_actors[row]->OnCollision(m_actors[column]);
					m_actors[column]->OnCollision(m_actors[row]);

				}
			}

		}
	}

	m_actors.Remove(m_actorsToBeRemoved);
	for (int i = 0; i < m_actorsToBeRemoved.Length(); i++)
	{
		delete m_actorsToBeRemoved[i];
		m_actorsToBeRemoved[i] = nullptr;
	}
	m_actorsToBeRemoved.Clear();
}

void Scene::End()
{
	for (int i = 0; i < m_actors.Length(); i++)
		m_actors[i]->End();
}

void Scene::DrawTiles()
{
}
