#include "TestScene.h"
#include "Engine/Actor.h"
#include "Game/Enemy.h"
#include "Game/Tile.h"
TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::Start()
{
	Scene::Start();
	Actor* bob = Actor::Instantiate(new Tile(2));
}

void TestScene::Update(double deltatime)
{
	Scene::Update(deltatime);
	
}
