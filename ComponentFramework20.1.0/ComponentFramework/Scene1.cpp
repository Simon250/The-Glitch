#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene1.h"
#include "Camera.h"
#include "Viper.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include "Debug.h"
#include "Physics.h"

Scene1::Scene1() : camera(nullptr), viper(nullptr), meshPtr(nullptr), shaderPtr(nullptr), texturePtr(nullptr) {
	Debug::Info("Created Scene0: ", __FILE__, __LINE__);
}

Scene1::~Scene1() {}

bool Scene1::OnCreate() {
	camera = new Camera();
	lightSource[0] = Vec3(0.0, 5.0, -10.0);
	lightSource[1] = Vec3(0.0, -5.0, -10.0);

	if (ObjLoader::loadOBJ("meshes/F-16C.obj") == false) {
		return false;
	}
	meshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("multiphongVert.glsl", "multiphongFrag.glsl");
	texturePtr = new Texture();
	if (meshPtr == nullptr || shaderPtr == nullptr || texturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}

	/*if (texturePtr->LoadImage("textures/mario_main.png") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}*/

	viper = new Viper(meshPtr, shaderPtr, nullptr);
	if (viper == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}
	viper->setPos(Vec3(-10.0, -5.0, 0.0));
	viper->setModelMatrix(MMath::translate(viper->getPos()) * MMath::rotate(180.0f, Vec3(0.0f, 0.0f, 1.0f)));

	return true;
}

void Scene1::HandleEvents(const SDL_Event& sdlEvent) {

}

void Scene1::Update(const float deltaTime) {

	viper->Update(deltaTime);
}

void Scene1::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	GLuint program = viper->getShader()->getProgram();
	glUseProgram(program);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(viper->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(viper->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniform3fv(viper->getShader()->getUniformID("lightPos[0]"), 2, lightSource[0]);


	viper->Render();

	glUseProgram(0);
}


void Scene1::OnDestroy() {
	if (camera) delete camera, camera = nullptr;
	if (meshPtr) delete meshPtr, meshPtr = nullptr;
	if (texturePtr) delete texturePtr, texturePtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	if (viper) delete viper, viper = nullptr;
}
