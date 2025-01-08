#include "Game.h"
#include "raylib.h"
#include "Engine\Transform2D.h"
#include "Engine\Actor.h"
#include "Engine/Scene/Scene.h"
#include "TextureManager.h"
#include "Engine/Scene/TestScene.h"
#include "Engine/Scene/MainMenu.h"
#include <chrono>
#include <iostream>

Scene* Game::m_currentscene = nullptr;
DynamicArray<Scene*> Game::m_scenes;
Game::Game()
{
    if (m_currentscene == nullptr)
    {
        m_currentscene = this->m_currentscene;
    }
    m_mainmenu = new MainMenu();
    m_testscene = new TestScene();
    m_texturemanager = new TextureManager();
}
Game::~Game()
{
    delete m_texturemanager;
}

void Game::Run()
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    SetTargetFPS(140);
    //Timing
   

    m_texturemanager->LoadTextures();
    AddScene(m_mainmenu);
    AddScene(m_testscene);

    SetCurrentScene(m_testscene);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        m_currentTime = std::chrono::high_resolution_clock::now();
        m_currentscene->Update(m_deltaTime);
       

        EndDrawing();

        m_lastTime = std::chrono::high_resolution_clock::now();
        m_deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(m_lastTime - m_currentTime).count() / 1000.0f;
        
    }
    m_currentscene->End();
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
    if (!m_scenes.Contains(scene))
        m_scenes.Add(scene);
    if (m_currentscene == nullptr)
        m_currentscene = scene;
    
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
