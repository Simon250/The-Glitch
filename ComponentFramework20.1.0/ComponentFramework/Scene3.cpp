#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene3.h"
#include "Camera.h"
#include "DemoObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include "Debug.h"
#include "Physics.h"

Scene3::Scene3() : camera(nullptr), demoObject(nullptr), meshPtr(nullptr), shaderPtr(nullptr), texturePtr(nullptr) {
	Debug::Info("Created Scene3: ", __FILE__, __LINE__);
}

Scene3::~Scene3() {}

bool Scene3::OnCreate() {
	camera = new Camera();
	skyBox = new SkyBox();
	if(!skyBox->OnCreate()){
		Debug::FatalError("SkyBox could not be created", __FILE__, __LINE__);
		return false;
	}
	camera->setSkyBox(skyBox);
	lightSource = Vec3(0.0, 0.0, 0.0);

	if (ObjLoader::loadOBJ("meshes/Cube.obj") == false) {
		return false;
	}
	meshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("SkyBoxVert.glsl", "SkyBoxFrag.glsl");
	texturePtr = new Texture();
	if (meshPtr == nullptr || shaderPtr == nullptr || texturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}


	/*if (texturePtr->LoadImage("textures/mario_main.png") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}*/

	demoObject = new DemoObject(meshPtr, shaderPtr, nullptr);
	if (demoObject == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}
	demoObject->setPos(Vec3(0.0, 0.0, -10.0));
	demoObject->setModelMatrix(MMath::translate(demoObject->getPos()) * MMath::rotate(70.0f, Vec3(0.0f, 1.0f, 0.0f)));

	return true;
}

void Scene3::HandleEvents(const SDL_Event& sdlEvent) {

}

void Scene3::Update(const float deltaTime) {

	demoObject->setAngVel(5.0f);
	Physics::RigidBodyRotation(*demoObject, deltaTime);
	Physics::SimpleNewtonMotion(*demoObject, deltaTime);

	demoObject->setModelMatrix(MMath::translate(demoObject->getPos()) * MMath::rotate(demoObject->getAng(), Vec3(0.0f, 1.0f, 0.0f)));
	


	demoObject->Update(deltaTime);
	camera->Update(deltaTime);
}

void Scene3::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	GLuint program = demoObject->getShader()->getProgram();
	camera->Render();
	glUseProgram(program);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(demoObject->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(demoObject->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniform3fv(demoObject->getShader()->getUniformID("lightPos"), 1, lightSource);

	demoObject->Render();

	glUseProgram(0);
}


void Scene3::OnDestroy() {
	if (camera) delete camera, camera = nullptr;
	if (meshPtr) delete meshPtr, meshPtr = nullptr;
	if (texturePtr) delete texturePtr, texturePtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	if (demoObject) delete demoObject, demoObject = nullptr;
	if (skyBox) delete skyBox, skyBox = nullptr;
}