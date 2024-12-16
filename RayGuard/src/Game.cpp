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
    
    Actor bob = Actor("Bob");
    Actor* jeff = Actor::Instantiate(new Actor("Jeff"), bob.Transform, MathLibrary::Vector2(10, 10));
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        DrawRectangle(bob.Transform->LocalPosition().x, bob.Transform->LocalPosition().y, 20, 20, BLACK);
        DrawRectangle(jeff->Transform->LocalPosition().x, jeff->Transform->LocalPosition().y, 20, 20, BLACK);
        if (IsKeyDown(KEY_W))
        {
            bob.Transform->Translate(bob.Transform->GetForward() * .5);
        }
        EndDrawing();
    }

    CloseWindow();



}
