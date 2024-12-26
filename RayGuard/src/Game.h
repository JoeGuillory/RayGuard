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

	 static Scene* GetCurrentScene() { return m_currentscene; }
	 void SetCurrentScene(Scene* scene);
	
	 void AddScene(Scene* scene);
	 bool RemoveScene(Scene* scene);
	 Scene* GetScene(int index);
	

private:
	static DynamicArray<Scene*> m_scenes;
	static Scene* m_currentscene;
	TextureManager* m_texturemanager;


};
