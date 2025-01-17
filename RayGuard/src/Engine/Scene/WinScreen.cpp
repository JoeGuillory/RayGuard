#include "WinScreen.h"
#include "Engine/Transform2D.h"
#include "Engine/Actor.h"
#include "Game/Tile.h"
#include "raylib.h"
#include "Game.h"
#include "Game/Button.h"







WinScreen::WinScreen()
{
}

WinScreen::~WinScreen()
{
}

void WinScreen::Start()
{
	Scene::Start();

	DrawTiles();
	Actor* esckey = Actor::Instantiate(new Button(7));
	esckey->Transform->Translate(605, 390);
}

void WinScreen::Update(double deltaTime)
{
	Scene::Update(deltaTime);

	
	
	DrawText("You Win!!!!", 185, 120, 90, BLUE);
	
	
	DrawText("Press Escape to Close ", 130, 400, 40, BLACK);
}

void WinScreen::End()
{
	Scene::End();
}

void WinScreen::DrawTiles()
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
