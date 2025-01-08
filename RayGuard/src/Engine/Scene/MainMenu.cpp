#include "MainMenu.h"
#include "Engine/Actor.h"
#include "Game/Tile.h"
#include "raylib.h"
#include "Game.h"
#include "Game/Button.h"
#include "Engine/Transform2D.h"

MainMenu::MainMenu()
{
}
// YOU ARE TRYING TO SET THE OTHERTILE AS THE BACKGROUND
MainMenu::~MainMenu()
{
}

void MainMenu::Start()
{
	Scene::Start();
	
	DrawTiles();
	Actor* esckey = Actor::Instantiate(new Button(7));
	Actor* enterkey = Actor::Instantiate(new Button(8));
	
	esckey->Transform->Translate(605, 170);
	enterkey->Transform->Translate(600, 120);
	

}

void MainMenu::Update(double deltatime)
{
	
	
	Scene::Update(deltatime);
	
	DrawText("Welcome to RayGuard", 120, 20, 50, BLACK);
	DrawText("Press Enter to Start ", 130, 130, 40, BLACK);
	
	DrawText("Press Escape to Close ", 130, 180, 40, BLACK);
	
	
	if (IsKeyPressed (KEY_ENTER))
	{
		Game::instance->SetCurrentScene(Game::instance->GetScene(1));
	}
}

void MainMenu::DrawTiles()
{
	auto tile = Actor::Instantiate;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			
				tile(new Button(9), nullptr, { (float)(i * 50),(float)(j * 50) }, 0.0f);
			
		}
	}

}

