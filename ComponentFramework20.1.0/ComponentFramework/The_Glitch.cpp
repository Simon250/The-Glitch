#include "The_Glitch.h"
#include <glew.h>
#include <iostream>
#include "Window.h"
#include "Debug.h"
#include "Camera.h"
#include "DemoObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include "Debug.h"
#include "Physics.h"

The_Glitch::The_Glitch() : camera(nullptr), playerModel(nullptr), meshPtr1(nullptr), meshPtr2(nullptr), shaderPtr(nullptr), texturePtr(nullptr) {
	playerSpeed = 10.0f;
	Debug::Info("Created The_Glitch: ", __FILE__, __LINE__);
}

The_Glitch::~The_Glitch() {}

bool The_Glitch::OnCreate() {
	numWalls = 11;
	camera = new Camera();

	if (ObjLoader::loadOBJ("meshes/Mario.obj") == false) {
		return false;
	}
	meshPtr1 = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("phongVert.glsl", "dimFrag.glsl");
	texturePtr = new Texture();
	if (meshPtr1 == nullptr || shaderPtr == nullptr || texturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}
	if (texturePtr->LoadImage("textures/skull_texture.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}

	playerModel = new DemoObject(meshPtr1, shaderPtr, texturePtr);
	if (playerModel == nullptr) {
		Debug::FatalError("Player Model could not be created", __FILE__, __LINE__);
		return false;
	}

	/*find mesh for wall segment then use array of objects to create the walls of the maze and have a loop somewhere to move all objects
	exept for player model in the oposite direction of the players movement to simulate motion.
	-do this for the glitches as well*/
	if (ObjLoader::loadOBJ("meshes/Cube.obj") == false) {
		return false;
	}
	meshPtr2 = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	if (meshPtr2 == nullptr || shaderPtr == nullptr || texturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}

	for (int i = 0; i < numWalls; i++) {
		wallSegment[i] = new WallSegment(meshPtr2, shaderPtr, texturePtr);
		if (wallSegment == nullptr) {
			Debug::FatalError("Wall Segment could not be created", __FILE__, __LINE__);
			return false;
		}
	}

	for (int i = 0; i < numWalls; i++) {
		wallSegment[i]->setPos(Vec3(100000.0f, 0.0f, -10.0f));
	}

	playerModel->setModelMatrix(MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::scale(0.4f, 0.4f, 0.4f));

	//Starting Room
	//left side wall
	wallSegment[0]->setPos(Vec3(-2.0f, 0.0f, -10.0f));
	wallSegment[1]->setPos(Vec3(-2.0f, 2.0f, -10.0f));
	wallSegment[2]->setPos(Vec3(-2.0f, -2.0f, -10.0f));

	//right side wall
	wallSegment[3]->setPos(Vec3( 4.0f, 0.0f, -10.0f));
	wallSegment[4]->setPos(Vec3( 4.0f, 2.0f, -10.0f));
	wallSegment[5]->setPos(Vec3( 4.0f, -2.0f, -10.0f));

	//back wall
	wallSegment[6]->setPos(Vec3(-2.0f, -4.0f, -10.0f));
	wallSegment[7]->setPos(Vec3( 0.0f, -4.0f, -10.0f));
	wallSegment[8]->setPos(Vec3( 2.0f, -4.0f, -10.0f));
	wallSegment[9]->setPos(Vec3(4.0f, -4.0f, -10.0f));

	//front wall
	wallSegment[10]->setPos(Vec3(0.0f, 2.0f, -10.0f));
	
	




	for (int i = 0; i < numWalls; i++) {
		wallSegment[i]->setModelMatrix(MMath::rotate(0.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::scale(0.4f, 0.4f, 0.4f));
	}

	lightSource = Vec3(0.0, 0.0, -9.0);

	return true;
}

void The_Glitch::OnDestroy() {
	if (camera) delete camera, camera = nullptr;
	if (meshPtr1) delete meshPtr1, meshPtr1 = nullptr;
	if (meshPtr2) delete meshPtr2, meshPtr2 = nullptr;
	if (texturePtr) delete texturePtr, texturePtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	if (playerModel) delete playerModel, playerModel = nullptr;
	for (int i = 0; i < numWalls; i++) {
		if (wallSegment[i]) delete wallSegment[i], wallSegment[i] = nullptr;
	}
}

void The_Glitch::HandleEvents(const SDL_Event& sdlEvent) {

	if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_W) {
		playerModel->setModelMatrix(MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::scale(0.4f, 0.4f, 0.4f));

		for (int i = 0; i < numWalls; i++) {
			wallSegment[i]->setVel(Vec3(0.0f, -15.0f, 0.0f));
			Physics::SimpleNewtonMotion(*wallSegment[i], deltaTime);
			wallSegment[i]->setModelMatrix(MMath::translate(wallSegment[i]->getPos()));
		}

		Debug::Info("Moved Up", __FILE__, __LINE__);
	}
	if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_A) {
		playerModel->setModelMatrix((MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::rotate(90.0f, Vec3(0.0f, 1.0f, 0.0f)) * MMath::scale(0.4f, 0.4f, 0.4f)));
		
		for (int i = 0; i < numWalls; i++) {
			wallSegment[i]->setVel(Vec3(15.0f, 0.0f, 0.0f));
			Physics::SimpleNewtonMotion(*wallSegment[i], deltaTime);
			wallSegment[i]->setModelMatrix(MMath::translate(wallSegment[i]->getPos()));
		}

		Debug::Info("Moved Left", __FILE__, __LINE__);
	}
	if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_S) {
		playerModel->setModelMatrix((MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::rotate(180.0f, Vec3(0.0f, -1.0f, 0.0f)) * MMath::scale(0.4f, 0.4f, 0.4f)));
		
		for (int i = 0; i < numWalls; i++) {
			wallSegment[i]->setVel(Vec3(0.0f, 15.0f, 0.0f));
			Physics::SimpleNewtonMotion(*wallSegment[i], deltaTime);
			wallSegment[i]->setModelMatrix(MMath::translate(wallSegment[i]->getPos()));
		}

		Debug::Info("Moved Down", __FILE__, __LINE__);
	}
	if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_D) {
		playerModel->setModelMatrix((MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::rotate(90.0f, Vec3(0.0f, -1.0f, 0.0f)) * MMath::scale(0.4f, 0.4f, 0.4f)));
		
		for (int i = 0; i < numWalls; i++) {
			wallSegment[i]->setVel(Vec3(-15.0f, 0.0f, 0.0f));
			Physics::SimpleNewtonMotion(*wallSegment[i], deltaTime);
			wallSegment[i]->setModelMatrix(MMath::translate(wallSegment[i]->getPos()));
		}

		Debug::Info("Moved Right", __FILE__, __LINE__);
	}
	if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_SPACE) {
		//attack
	}
	if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_LSHIFT) {
		//roll
	}
	if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_E) {
		//interact
	}

}

void The_Glitch::Update(const float deltaTime_) {
	deltaTime = deltaTime_;
	playerModel->Update(deltaTime_);

	for (int i = 0; i < numWalls; i++) {
		wallSegment[i]->Update(deltaTime_);
	}
}

void The_Glitch::Render() const {
	/// Clear the screen
	glClearColor(0.01f, 0.01f, 0.01f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	GLuint program = playerModel->getShader()->getProgram();
	glUseProgram(program);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(playerModel->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(playerModel->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniform3fv(playerModel->getShader()->getUniformID("lightPos"), 1, lightSource);
	
	for (int i = 0; i < numWalls; i++) {
		glUniformMatrix4fv(wallSegment[i]->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
		glUniformMatrix4fv(wallSegment[i]->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
		glUniform3fv(wallSegment[i]->getShader()->getUniformID("lightPos"), 1, lightSource);
	}


	playerModel->Render();

	for (int i = 0; i < numWalls; i++) {
		Vec3 temp = wallSegment[i]->getPos();
		if (temp.x < 20 && temp.x > -20 && temp.y < 20 && temp.y > -20) {
			wallSegment[i]->Render();
		}
	}

	glUseProgram(0);
}