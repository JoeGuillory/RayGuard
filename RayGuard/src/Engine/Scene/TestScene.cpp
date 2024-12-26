#include "TestScene.h"
#include "Engine/Actor.h"
#include "Game/Enemy.h"
TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::Start()
{
	Scene::Start();
	Actor* bob = Actor::Instantiate(new Enemy("bob"));
}

void TestScene::Update(double deltatime)
{
	Scene::Update(deltatime);
	
}
