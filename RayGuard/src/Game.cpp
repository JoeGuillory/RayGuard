#include "Game.h"
#include "raylib.h"
#include "Engine\Transform2D.h"
#include "Engine\Actor.h"
#include <iostream>
#include "Engine/Scene/Scene.h"
#include "TextureManager.h"



Game::Game()
{
    m_texturemanager = new TextureManager();
}
Game::~Game()
{
    delete m_texturemanager;
}

void Game::Run()
{

    InitWindow(800, 450, "raylib [core] example - basic window");
    
    m_texturemanager->LoadTextures();
   
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hi", 190, 200, 20, LIGHTGRAY);

        
      
        EndDrawing();
    }

    CloseWindow();



}

void Game::SetCurrentScene(Scene* scene)
{
    if (m_currentscene != nullptr)
        m_currentscene->End();
    m_currentscene = scene;
    m_currentscene->Start();
}

void Game::AddScene(Scene* scene)
{
    for (Scene* element : m_scenes)
    {
        if (element = scene)
        {
            
        }
        else
        {
            m_scenes.Add(scene);
            if (m_currentscene == nullptr)
            {
                m_currentscene = scene;
            }
        }
    }
    
}

bool Game::RemoveScene(Scene* scene)
{
    m_scenes.Remove(scene);
    if (m_currentscene == scene)
    {
        m_currentscene = m_scenes[0];
    }
    return true;
}

Scene* Game::GetScene(int index)
{
    if (m_scenes.Length() <= 0 || m_scenes.Length() <= index || index < 0)
        return nullptr;
    return m_scenes[index];
}
