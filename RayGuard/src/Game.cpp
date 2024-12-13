#include "Game.h"
#include "raylib.h"
#include "Engine\Transform2D.h"
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
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();



}