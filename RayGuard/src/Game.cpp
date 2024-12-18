#include "Game.h"
#include "raylib.h"
#include "Engine\Transform2D.h"
#include "Engine\Actor.h"
#include <iostream>

Game::Game() {}
Game::~Game() {}

void Game::Run()
{

    InitWindow(800, 450, "raylib [core] example - basic window");
    
 


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hi", 190, 200, 20, LIGHTGRAY);

        
      
        EndDrawing();
    }

    CloseWindow();



}
