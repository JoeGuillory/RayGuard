#include "TestScene.h"
#include "Engine/Actor.h"
#include "Game/Enemy.h"
#include "Game/Tile.h"
#include "Engine/Transform2D.h"
#include "Game.h"

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
	Game::GetCurrentScene();
	
}

void TestScene::Update(double deltatime)
{
	Scene::Update(deltatime);

	
}

void TestScene::DrawTiles()
{
	auto tile = Actor::Instantiate;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j == 4)
				tile(new Tile(3), nullptr, { (float)(i * 50),(float)(j * 50) }, 0.0f);
			else
			{

				tile(new Tile(2), nullptr, { (float)(i * 50),(float)(j * 50) }, 0.0f);
			}
		}
	}

}


