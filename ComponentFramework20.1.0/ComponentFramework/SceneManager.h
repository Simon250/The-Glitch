#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <string>
class SceneManager  {
public:
	
	SceneManager();
	~SceneManager();
	void Run();
	bool Initialize(std::string name_, int width_, int height_);
	void GetEvents();
	
	
private:
	enum SCENE_NUMBER {
		SCENE0 = 0,
		SCENE1,
		SCENE2,
		SCENE3,
		SCENE4,
		SCENE5,
		SCENE6,
		THE_GLITCH1
	};

	class Scene* currentScene;
	class Timer* timer;
	class Window* window;

	unsigned int fps;
	bool isRunning;
	void BuildScene(SCENE_NUMBER scene_);
};


#endif // SCENEMANAGER_H