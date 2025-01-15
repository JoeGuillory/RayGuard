#include "Engine/Actor.h"
#include "Game/Tile.h"
#include "raylib.h"
#include "Game.h"
#include "Game/Button.h"
#include "Engine/Transform2D.h"
#include "GameOver.h"

GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::Start()
{
	Scene::Start();

	DrawTiles();
	Actor* esckey = Actor::Instantiate(new Button(7));
	Actor* enterkey = Actor::Instantiate(new Button(8));

	esckey->Transform->Translate(605, 170);
	enterkey->Transform->Translate(600, 120);


}

void GameOver::Update(double deltatime)
{


	Scene::Update(deltatime);

	DrawText("GameOver", 120, 20, 50, RED);
	DrawText("Press Enter to Restart ", 130, 130, 40, BLACK);

	DrawText("Press Escape to Close ", 130, 180, 40, BLACK);


	if (IsKeyPressed(KEY_ENTER))
	{
		Game::instance->SetCurrentScene(Game::instance->GetScene(1));
	}
}

void GameOver::End()
{
	Scene::End();

	
}
void GameOver::DrawTiles()
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
