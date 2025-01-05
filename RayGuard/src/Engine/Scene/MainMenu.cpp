#include "MainMenu.h"
#include "Engine/Actor.h"
#include "Game/Tile.h"
#include "raylib.h"
MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Start()
{
	Scene::Start();
	


}

void MainMenu::Update(double deltatime)
{
	Scene::Update(deltatime);
	ClearBackground(DARKGREEN);
	DrawText("Welcome to RayGuard", 120, 20, 50, BLACK);
	
}

