#pragma once
#include "DynamicArray.h"

class TextureManager;
class Scene;
class Game
{
public:
	Game();
	~Game();
	void Run();

	 Scene* GetCurrentScene() { return m_currentscene; }
	 void SetCurrentScene(Scene* scene);
	
	 void AddScene(Scene* scene);
	 bool RemoveScene(Scene* scene);
	 Scene* GetScene(int index);
	

private:
	DynamicArray<Scene*> m_scenes;
	Scene* m_currentscene;
	TextureManager* m_texturemanager;


};