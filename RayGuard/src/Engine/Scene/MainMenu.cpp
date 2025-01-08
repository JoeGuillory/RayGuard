#include "MainMenu.h"
#include "Engine/Actor.h"
#include "Game/Tile.h"
#include "raylib.h"
#include "Game.h"
MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Start()
{
	Scene::Start();
	Game::GetCurrentScene;
	


}

void MainMenu::Update(double deltatime)
{
	Scene::Update(deltatime);
	ClearBackground(DARKGREEN);
	DrawText("Welcome to RayGuard", 120, 20, 50, BLACK);
	if (IsKeyPressed (KEY_ENTER))
	{
		Game::instance->SetCurrentScene(Game::instance->GetScene(1));
	}
}
