#include "Game.h"
#include "raylib.h"
#include "Engine\Transform2D.h"
#include "Engine\Actor.h"
#include "Engine/Scene/Scene.h"
#include "TextureManager.h"
#include "Engine/Scene/TestScene.h"
#include "Engine/Scene/MainMenu.h"
#include <chrono>

// Pointer to the current scene
Scene* Game::m_currentscene = nullptr;

// Dynamic array to hold all of the scenes
DynamicArray<Scene*> Game::m_scenes;

Game::Game()
{
    
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

    //Timing
   
    m_currentTime = std::chrono::high_resolution_clock::now();
    m_lastTime = m_currentTime;

    // Load textures using the texture manager 
    m_texturemanager->LoadTextures();
    AddScene(m_mainmenu);
    AddScene(m_testscene);

    SetCurrentScene(m_mainmenu);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        m_currentTime = std::chrono::high_resolution_clock::now();
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
    // If there is an existing scene
    if (m_currentscene != nullptr)
    // End the previous scene before switching to the new 
        m_currentscene->End();
    // Set the new scene
    m_currentscene = scene;
    // Start the new scene
    m_currentscene->Start();
}

void Game::AddScene(Scene* scene)
{
    // If the scene is not in the list
    if (!m_scenes.Contains(scene))
        // Add the scene to the dynamic array
        m_scenes.Add(scene);
    // If there is no scene set the new scene as the curent 
    if (m_currentscene == nullptr)
        m_currentscene = scene;
    
}

bool Game::RemoveScene(Scene* scene)
{
    m_scenes.Remove(scene);
    // If the current scene is being removed set the first scene in the list as the new current scene
    if (m_currentscene == scene)
    { // Setting the first scene 
        m_currentscene = m_scenes[0];
    }
    return true;
}

Scene* Game::GetScene(int index)
{
    // If the index is out of bounds (either negative or greater than the number of scenes
    if (m_scenes.Length() <= 0 || m_scenes.Length() <= index || index < 0)
        return nullptr;
    return m_scenes[index];
}
