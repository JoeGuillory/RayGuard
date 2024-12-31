#include "Game.h"
#include "raylib.h"
#include "Engine\Transform2D.h"
#include "Engine\Actor.h"
#include "Engine/Scene/Scene.h"
#include "TextureManager.h"
#include "Engine/Scene/TestScene.h"
#include <chrono>

Scene* Game::m_currentscene = nullptr;
DynamicArray<Scene*> Game::m_scenes;
Game::Game()
{
    if (m_currentscene == nullptr)
    {
        m_currentscene = this->m_currentscene;
    }
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

    //Timing
   
    m_currentTime = std::chrono::high_resolution_clock::now();
    
    
    m_texturemanager->LoadTextures();
    AddScene(m_testscene);

    SetCurrentScene(m_testscene);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
       
        m_currentscene->Update(m_deltaTime.count());
       

        EndDrawing();

        m_deltaTime = m_currentTime - m_lastTime;
        m_lastTime = m_currentTime;
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
