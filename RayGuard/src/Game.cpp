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
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
       
        Actor bob = Actor((char*)"bob");
        RAYLIB_H::Vector2 location = { bob.Transform->LocalPosition().x,bob.Transform->LocalPosition().y };
        DrawRectangleV(location, {100,100},BLACK);
        EndDrawing();
    }

    CloseWindow();



}
