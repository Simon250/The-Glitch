#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene2.h"
#include "Camera.h"
#include "DemoObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include "Debug.h"
#include "Physics.h"

Scene2::Scene2() : camera(nullptr), meshPtr(nullptr), shaderPtr(nullptr), texturePtr(nullptr) {
	Debug::Info("Created Scene2: ", __FILE__, __LINE__);
}

Scene2::~Scene2() {}

bool Scene2::OnCreate() {
	camera = new Camera();
	lightSource = Vec3(0.0, 0.0, 10.0);

	if (ObjLoader::loadOBJ("meshes/Sphere.obj") == false) {
		return false;
	}
	meshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("textureVert.glsl", "textureFrag.glsl");
	texturePtr = new Texture();
	marsTextPtr = new Texture();
	moonTextPtr = new Texture();
	marioTextPtr = new Texture();
	if (meshPtr == nullptr || shaderPtr == nullptr || texturePtr == nullptr || marsTextPtr == nullptr || moonTextPtr == nullptr || marioTextPtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}

	if (marsTextPtr->LoadImage("textures/mars.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}
	if (texturePtr->LoadImage("textures/earthclouds.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}
	if (moonTextPtr->LoadImage("textures/moon.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}
	if (marioTextPtr->LoadImage("textures/mario_fire.png") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}

	orbObj[0] = new DemoObject(meshPtr, shaderPtr, texturePtr);
	orbObj[1] = new DemoObject(meshPtr, shaderPtr, marsTextPtr);
	orbObj[2] = new DemoObject(meshPtr, shaderPtr, moonTextPtr);
	orbObj[3] = new DemoObject(meshPtr, shaderPtr, marioTextPtr);
	if (orbObj[0] == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}
	orbObj[0]->setPos(Vec3(0.0, 0.0, -10.0));
	orbObj[0]->setModelMatrix(MMath::translate(orbObj[0]->getPos()));

	orbObj[1]->setPos(Vec3(-8.0, 0.0, -10.0));
	orbObj[1]->setModelMatrix(MMath::translate(orbObj[0]->getPos()));

	orbObj[2]->setPos(Vec3(-12.0, 0.0, -10.0));
	orbObj[2]->setModelMatrix(MMath::translate(orbObj[0]->getPos()));

	orbObj[3]->setPos(Vec3(-14.0, 0.0, -10.0));
	orbObj[3]->setModelMatrix(MMath::translate(orbObj[0]->getPos()));

	return true;
}

void Scene2::HandleEvents(const SDL_Event& sdlEvent) {

}

void Scene2::Update(const float deltaTime) {
	for (int i = 0; i < 4; i++) {
		orbObj[i]->Update(deltaTime);
	}
	
	static float rotation = 0.0f;
	rotation += 1.0f;


	Physics::RigidBodyRotation(*orbObj[0], deltaTime);
	orbObj[0]->setModelMatrix(MMath::translate(orbObj[0]->getPos()) * MMath::rotate(rotation, Vec3(0.0f, 1.0f, 0.0f)));


	orbObj[1]->setAngVel(10.0f);
	Physics::RigidBodyRotation(*orbObj[1], deltaTime);
	orbObj[1]->setModelMatrix(MMath::translate(MMath::rotate(orbObj[1]->getAng(), Vec3(0.0f, 0.0f, 1.0f))*orbObj[1]->getPos()) * MMath::rotate(rotation, Vec3(0.0f, 1.0f, 0.0f)));

	orbObj[2]->setAngVel(-20.0f);
	Vec3 localcoord = Vec3(-4.0f, 0.0f, 0.0f);
	Physics::RigidBodyRotation(*orbObj[2], deltaTime);
	orbObj[2]->setModelMatrix(MMath::translate((MMath::rotate(orbObj[1]->getAng(), Vec3(0.0f, 0.0f, 1.0f)) * orbObj[1]->getPos()) + (MMath::rotate(orbObj[2]->getAng(), Vec3(0.0f, 0.0f, 1.0f)) * localcoord)) * MMath::rotate(rotation, Vec3(0.0f, 1.0f, 0.0f)) * MMath::scale(Vec3(0.5f, 0.5f, 0.5f)));


	orbObj[3]->setAngVel(15.0f);
	Vec3 localcoord1 = Vec3(-2.0f, 0.0f, 0.0f);
	Physics::RigidBodyRotation(*orbObj[3], deltaTime);
	orbObj[3]->setModelMatrix(MMath::translate((MMath::rotate(orbObj[1]->getAng(), Vec3(0.0f, 0.0f, 1.0f)) * orbObj[1]->getPos()) + (MMath::rotate(orbObj[2]->getAng(), Vec3(0.0f, 0.0f, 1.0f)) * localcoord) + (MMath::rotate(orbObj[3]->getAng(), Vec3(0.0f, 0.0f, 1.0f)) * localcoord1)) * MMath::rotate(rotation, Vec3(0.0f, 1.0f, 0.0f)) * MMath::scale(Vec3(0.5f, 0.5f, 0.5f)));

}

void Scene2::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	GLuint program = orbObj[0]->getShader()->getProgram();
	glUseProgram(program);

	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(orbObj[0]->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(orbObj[0]->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
	glUniform3fv(orbObj[0]->getShader()->getUniformID("lightPos"), 1, lightSource);

	for (int i = 0; i < 4; i++) {
		orbObj[i]->Render();
	}
	

	glUseProgram(0);
}


void Scene2::OnDestroy() {
	if (camera) delete camera, camera = nullptr;
	if (meshPtr) delete meshPtr, meshPtr = nullptr;
	if (texturePtr) delete texturePtr, texturePtr = nullptr;
	if (marsTextPtr) delete marsTextPtr, marsTextPtr = nullptr;
	if (moonTextPtr) delete moonTextPtr, moonTextPtr = nullptr;
	if (marioTextPtr) delete marioTextPtr, marioTextPtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	for (int i = 0; i < 4; i++) {
		if (orbObj[i]) delete orbObj[i];
	}
	for (int i = 0; i < 4; i++) {
		orbObj[i] = nullptr;
	}
	
}