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
	Actor::Instantiate(new SpawnManager());
}

void LevelOne::Update(double deltaTime)
{
	Scene::Update(deltaTime);
	

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
