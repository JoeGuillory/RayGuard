#include "TestScene.h"
#include "Engine/Actor.h"
#include "Game/Enemy.h"
#include "Game/Tile.h"
#include "Engine/Components/IsClicked.h"
#include "Engine/Transform2D.h"
#include "TextureManager.h"
#include "Game.h"
#include "Game/Tower.h"
#include "Engine/Components/Spawner.h"


TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::Start()
{
	Scene::Start();
	DrawTiles();
	
	
	
}

void TestScene::Update(double deltatime)
{
	Scene::Update(deltatime);
	
}

void TestScene::DrawTiles()
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
				dynamic_cast<Tile*>(actor)->SetTileNumber((inumber + jnumber)-1);
			}
			else
			{
				actor = tile(new Tile(2), nullptr, { (float)(i * 50),(float)(j * 50) }, 0.0f);
				dynamic_cast<Tile*>(actor)->SetTileNumber((inumber + jnumber) -1);
			}
			jnumber++;
		
		}
		
	}

}


