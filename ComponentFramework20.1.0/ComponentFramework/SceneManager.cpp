#include <SDL.h>
#include "SceneManager.h"
#include "Timer.h"
#include "Window.h"
#include "Scene0.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"
#include "Scene4.h"
#include "Scene5.h"
#include "Scene6.h"
#include "The_Glitch.h"


SceneManager::SceneManager(): 
	currentScene(nullptr), window(nullptr), timer(nullptr),
	fps(60), isRunning(false) {}

SceneManager::~SceneManager() {
	if (currentScene) {
		currentScene->OnDestroy();
		delete currentScene;
		currentScene = nullptr;
	}
	
	if (timer) {
		delete timer;
		timer = nullptr;
	}

	if (window) {
		delete window;
		window = nullptr;
	}
	Debug::Info("Deleting the GameSceneManager", __FILE__, __LINE__);

}

bool SceneManager::Initialize(std::string name_, int width_, int height_) {

	window = new Window();
	if (!window->OnCreate(name_, width_, height_)) {
		Debug::FatalError("Failed to initialize Window object", __FILE__, __LINE__);
		return false;
	}

	timer = new Timer();
	if (timer == nullptr) {
		Debug::FatalError("Failed to initialize Timer object", __FILE__, __LINE__);
		return false;
	}
	
	BuildScene(THE_GLITCH1);
	
	return true;
}


void SceneManager::Run() {
	timer->Start();
	isRunning = true;
	while (isRunning) {
		timer->UpdateFrameTicks();
		currentScene->Update(timer->GetDeltaTime());
		currentScene->Render();
		GetEvents();
		SDL_GL_SwapWindow(window->getWindow());
		SDL_Delay(timer->GetSleepTime(fps));
	}
}

void SceneManager::GetEvents() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		if (sdlEvent.type == SDL_EventType::SDL_QUIT) {
			isRunning = false;
			return;
		}
		else if (sdlEvent.type == SDL_KEYDOWN) {
			switch (sdlEvent.key.keysym.scancode) {
			case SDL_SCANCODE_ESCAPE:
			case SDL_SCANCODE_Q:
				isRunning = false;
				return;

			case SDL_SCANCODE_F1:
				BuildScene(SCENE1);
				break;

			case SDL_SCANCODE_F2:
				BuildScene(SCENE2);
				break;

			case SDL_SCANCODE_F3:
				BuildScene(SCENE3);
				break;

			case SDL_SCANCODE_F4:
				BuildScene(SCENE4);
				break;

			case SDL_SCANCODE_F5:
				BuildScene(SCENE5);
				break;

			case SDL_SCANCODE_F6:
				BuildScene(SCENE6);
				break;

			case SDL_SCANCODE_F7:
				BuildScene(THE_GLITCH1);
				break;

			case SDL_SCANCODE_O:
				BuildScene(SCENE0);
				break;
			default:
				currentScene->HandleEvents(sdlEvent);
				break;
			}
		}
		if (currentScene == nullptr) {
			Debug::FatalError("Failed to initialize Scene", __FILE__, __LINE__);
			isRunning = false;
			return;
		}
		
	}
}

void SceneManager::BuildScene(SCENE_NUMBER scene) {
	bool status; 

	if (currentScene != nullptr) {
		delete currentScene;
		currentScene = nullptr;
	}

	switch (scene) {
	case SCENE0:  
		currentScene = new Scene0();
		status = currentScene->OnCreate();
		break;

	case SCENE1:
		currentScene = new Scene1();
		status = currentScene->OnCreate();
		break;

	case SCENE2:
		currentScene = new Scene2();
		status = currentScene->OnCreate();
		break;

	case SCENE3:
		currentScene = new Scene3();
		status = currentScene->OnCreate();
		break;

	case SCENE4:
		currentScene = new Scene4();
		status = currentScene->OnCreate();
		break;

	case SCENE5:
		currentScene = new Scene5();
		status = currentScene->OnCreate();
		break;

	case SCENE6:
		currentScene = new Scene6();
		status = currentScene->OnCreate();
		break;

	case THE_GLITCH1:
		currentScene = new The_Glitch();
		status = currentScene->OnCreate();
		break;

	default:
		Debug::Error("Incorrect scene number assigned in the manager", __FILE__, __LINE__);
		currentScene = nullptr;
		break;
	}	
}


