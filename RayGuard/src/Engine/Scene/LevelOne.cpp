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
	
}

void LevelOne::Update(double deltaTime)
{
	Scene::Update(deltaTime);
	if (!dynamic_cast<SpawnManager*>(m_spawnmanager)->IsRoundFinished())
	{
		strncpy_s(m_round, "Round: ", 7);
		strncat_s(m_round, std::to_string(dynamic_cast<SpawnManager*>(m_spawnmanager)->GetRound()).c_str(), 3);
		DrawText( m_round , GetScreenWidth() / 3, 10, 60, BLACK);

		strncpy_s(m_money, "Money: ", 7);
		strncat_s(m_money, std::to_string((int)GameManager::instance->GetMoney()).c_str(), 4);

		DrawText(m_money, 600, 300, 20, BLACK);
	}
	else if (dynamic_cast<SpawnManager*>(m_spawnmanager)->IsCompleted())
	{
		// Get next Game scene

	}

}

void LevelOne::End()
{
	Scene::End();
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
