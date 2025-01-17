#include "LevelOne.h"
#include "Engine/Actor.h"
#include "Game/Enemy.h"
#include "Game/Tile.h"
#include "Engine/Components/IsClicked.h"
#include "Engine/Transform2D.h"
#include "TextureManager.h"
#include "Game.h"
#include "Game/Tower.h"
#include "Engine/Components/Spawner.h"
#include "Game/SpawnManager.h"
#include <string>
#include "Engine/GameManager.h"
#include "Base.h"

LevelOne::LevelOne()
{
}

LevelOne::~LevelOne()
{
}

void LevelOne::Start()
{
	Scene::Start();
	DrawTiles();
	m_spawnmanager = Actor::Instantiate(new SpawnManager(5),nullptr,{850,225});
	Actor::Instantiate(new Base());
}

void LevelOne::Update(double deltaTime)
{
	Scene::Update(deltaTime);
	if (!dynamic_cast<SpawnManager*>(m_spawnmanager)->IsRoundFinished())
	{
		strncpy_s(m_round, "Round: ", 7);
		strncat_s(m_round, std::to_string(dynamic_cast<SpawnManager*>(m_spawnmanager)->GetRound()).c_str(), 3);
		DrawText( m_round , GetScreenWidth() / 3, 10, 60, BLACK);

		strncpy_s(m_money, "Gold: ", 7);
		strncat_s(m_money, std::to_string((int)GameManager::instance->GetMoney()).c_str(), 4);

		DrawText(m_money, 50, 350, 60, BLACK);
	}
	else if (dynamic_cast<SpawnManager*>(m_spawnmanager)->IsCompleted())
	{
		// Get next Game scene
		Game::instance->SetCurrentScene(Game::instance->GetScene(4));
	}
	if (GameManager::instance->GetPlayerHealth() <= 0)
	{
		GameManager::instance->Reset();
		Game::instance->SetCurrentScene(Game::instance->GetScene(2));
	}
}

void LevelOne::End()
{
	Scene::End();
	for (int i = 0; i < m_actors.Length(); i++)
		RemoveActor(m_actors[i]);
}

void LevelOne::DrawTiles()
{

	auto tile = Actor::Instantiate;
	int inumber = 0;
	int jnumber = 0;
	Actor* actor;
	for (int i = 0; i < 16; i++)
	{
		inumber++;
		for (int j = 0; j < 9; j++)
		{

			if (j == 4)
			{
				actor = tile(new Tile(3), nullptr, { (float)(i * 50),(float)(j * 50) }, 0.0f);
				dynamic_cast<Tile*>(actor)->SetTileNumber((inumber + jnumber) - 1);
			}
			else
			{
				actor = tile(new Tile(2), nullptr, { (float)(i * 50),(float)(j * 50) }, 0.0f);
				dynamic_cast<Tile*>(actor)->SetTileNumber((inumber + jnumber) - 1);
			}
			jnumber++;

		}

	}
}
