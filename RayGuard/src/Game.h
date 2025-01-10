#pragma once
#include "DynamicArray.h"
#include <chrono>
class TextureManager;
class Scene;
class Game
{
public:
	Game();
	~Game();
	void Run();

	 static Scene* GetCurrentScene() { return m_currentscene; }
	 static void SetCurrentScene(Scene* scene);
	
	 void AddScene(Scene* scene);
	 bool RemoveScene(Scene* scene);
	 static Scene* GetScene(int index);
	 static Game* instance;

private:
	Scene* m_mainmenu;
	Scene* m_testscene;
	Scene* m_levelOne;
	static DynamicArray<Scene*> m_scenes;
	static Scene* m_currentscene;
	TextureManager* m_texturemanager;
	std::chrono::time_point<std::chrono::steady_clock> m_currentTime;
	std::chrono::time_point<std::chrono::steady_clock> m_lastTime;
	
	double m_deltaTime;

};
