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
	numWalls = 165;
	numDoors = 10;
	camera = new Camera();
	levelGen = new Level1Gen();
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
		wallSegment[i] = new WallSegment(meshPtr2, shaderPtr, nullptr);
		if (wallSegment == nullptr) {
			Debug::FatalError("Wall Segment could not be created", __FILE__, __LINE__);
			return false;
		}
	}

	for (int i = 0; i < numWalls; i++) {
		wallSegment[i]->setPos(Vec3(100000.0f, 0.0f, -10.0f));
	}

	if (ObjLoader::loadOBJ("meshes/Cube.obj") == false) {
		return false;
	}
	meshPtr3 = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	if (meshPtr3 == nullptr || shaderPtr == nullptr || texturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}

	for (int i = 0; i < numDoors; i++) {
		doors[i] = new Door(meshPtr3, shaderPtr, nullptr);
		if (doors[i] == nullptr) {
			Debug::FatalError("Wall Segment could not be created", __FILE__, __LINE__);
			return false;
		}
	}
	for (int i = 0; i < numDoors; i++) {
		doors[i]->setPos(Vec3(100000.0f, 0.0f, -10.0f));
	}

	playerModel->setModelMatrix(MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::scale(0.4f, 0.4f, 0.4f));
	//Tutorial Level Set Up Start
	//some how need to put text boxes with breif descriptions of base mechanics in each room
	//Starting Room
	/*
		~~ ~
		|  |
		|  |
		~~~~
	*/
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

	//Floor
	wallSegment[65]->setPos(Vec3(0.0f, -2.0f, -12.0f));
	wallSegment[66]->setPos(Vec3(2.0f, -2.0f, -12.0f));
	wallSegment[67]->setPos(Vec3(0.0f, 0.0f, -12.0f));
	wallSegment[68]->setPos(Vec3(2.0f, 0.0f, -12.0f));
	wallSegment[69]->setPos(Vec3(2.0f, 2.0f, -12.0f));
	/*Door Explanation room
		
		~~~ ~~~
		|	  |
		|	  |
		|	  |
		|	  |
		~~~~~ ~
	
	*/
	//bottom wall
	wallSegment[11]->setPos(Vec3(-8.0f, 4.0f, -10.0f));
	wallSegment[12]->setPos(Vec3(-6.0f, 4.0f, -10.0f));
	wallSegment[13]->setPos(Vec3(-4.0f, 4.0f, -10.0f));
	wallSegment[14]->setPos(Vec3(-2.0f, 4.0f, -10.0f));
	wallSegment[15]->setPos(Vec3(0.0f, 4.0f, -10.0f));
	wallSegment[16]->setPos(Vec3(4.0f, 4.0f, -10.0f));
	//left wall
	wallSegment[17]->setPos(Vec3(-8.0f, 6.0f, -10.0f));
	wallSegment[18]->setPos(Vec3(-8.0f, 8.0f, -10.0f));
	wallSegment[19]->setPos(Vec3(-8.0f, 10.0f, -10.0f));
	wallSegment[20]->setPos(Vec3(-8.0f, 12.0f, -10.0f));
	//right wall
	wallSegment[21]->setPos(Vec3(4.0f, 6.0f, -10.0f));
	wallSegment[22]->setPos(Vec3(4.0f, 8.0f, -10.0f));
	wallSegment[23]->setPos(Vec3(4.0f, 10.0f, -10.0f));
	wallSegment[24]->setPos(Vec3(4.0f, 12.0f, -10.0f));
	//top wall
	wallSegment[25]->setPos(Vec3(-8.0f, 14.0f, -10.0f));
	wallSegment[26]->setPos(Vec3(-6.0f, 14.0f, -10.0f));
	wallSegment[27]->setPos(Vec3(-4.0f, 14.0f, -10.0f));
	wallSegment[28]->setPos(Vec3(0.0f, 14.0f, -10.0f));
	wallSegment[29]->setPos(Vec3(2.0f, 14.0f, -10.0f));
	wallSegment[30]->setPos(Vec3(4.0f, 14.0f, -10.0f));
	//floor
	wallSegment[70]->setPos(Vec3(2.0f, 4.0f, -12.0f));
	wallSegment[71]->setPos(Vec3(2.0f, 6.0f, -12.0f));
	wallSegment[72]->setPos(Vec3(0.0f, 6.0f, -12.0f));
	wallSegment[73]->setPos(Vec3(-2.0f, 6.0f, -12.0f));
	wallSegment[74]->setPos(Vec3(-4.0f, 6.0f, -12.0f));
	wallSegment[75]->setPos(Vec3(-6.0f, 6.0f, -12.0f));
	wallSegment[76]->setPos(Vec3(-6.0f, 8.0f, -12.0f));
	wallSegment[77]->setPos(Vec3(-4.0f, 8.0f, -12.0f));
	wallSegment[78]->setPos(Vec3(-2.0f, 8.0f, -12.0f));
	wallSegment[79]->setPos(Vec3(0.0f, 8.0f, -12.0f));
	wallSegment[80]->setPos(Vec3(2.0f, 8.0f, -12.0f));
	wallSegment[81]->setPos(Vec3(2.0f, 10.0f, -12.0f));
	wallSegment[82]->setPos(Vec3(0.0f, 10.0f, -12.0f));
	wallSegment[83]->setPos(Vec3(-2.0f, 10.0f, -12.0f));
	wallSegment[84]->setPos(Vec3(-4.0f, 10.0f, -12.0f));
	wallSegment[85]->setPos(Vec3(-6.0f, 10.0f, -12.0f));
	wallSegment[86]->setPos(Vec3(-6.0f, 12.0f, -12.0f));
	wallSegment[87]->setPos(Vec3(-4.0f, 12.0f, -12.0f));
	wallSegment[88]->setPos(Vec3(-2.0f, 12.0f, -12.0f));
	wallSegment[89]->setPos(Vec3(0.0f, 12.0f, -12.0f));
	wallSegment[90]->setPos(Vec3(2.0f, 12.0f, -12.0f));
	wallSegment[91]->setPos(Vec3(-2.0f, 14.0f, -12.0f));
	/*Enemy Explanation Room
		
		~|/|~
		|   |
		|   |
		|   |
		|   |
		|   |~~~~~
		|		 |
		|		 |
		|   |~~~~~
		|   |
		|   |
	*/
	//Left Wall
	wallSegment[31]->setPos(Vec3(-6.0f, 16.0f, -10.0f));
	wallSegment[32]->setPos(Vec3(-6.0f, 18.0f, -10.0f));
	wallSegment[33]->setPos(Vec3(-6.0f, 20.0f, -10.0f));
	wallSegment[34]->setPos(Vec3(-6.0f, 22.0f, -10.0f));
	wallSegment[35]->setPos(Vec3(-6.0f, 24.0f, -10.0f));
	wallSegment[36]->setPos(Vec3(-6.0f, 26.0f, -10.0f));
	wallSegment[37]->setPos(Vec3(-6.0f, 28.0f, -10.0f));
	wallSegment[38]->setPos(Vec3(-6.0f, 30.0f, -10.0f));
	wallSegment[39]->setPos(Vec3(-6.0f, 32.0f, -10.0f));
	wallSegment[40]->setPos(Vec3(-6.0f, 34.0f, -10.0f));
	wallSegment[41]->setPos(Vec3(-6.0f, 36.0f, -10.0f));
	//Right Wall
	wallSegment[42]->setPos(Vec3(2.0f, 16.0f, -10.0f));
	wallSegment[43]->setPos(Vec3(2.0f, 18.0f, -10.0f));
	wallSegment[44]->setPos(Vec3(2.0f, 20.0f, -10.0f));
	wallSegment[45]->setPos(Vec3(2.0f, 26.0f, -10.0f));
	wallSegment[46]->setPos(Vec3(2.0f, 28.0f, -10.0f));
	wallSegment[47]->setPos(Vec3(2.0f, 30.0f, -10.0f));
	wallSegment[48]->setPos(Vec3(2.0f, 32.0f, -10.0f));
	wallSegment[49]->setPos(Vec3(2.0f, 34.0f, -10.0f));
	wallSegment[50]->setPos(Vec3(2.0f, 36.0f, -10.0f));
	//Top Wall
	wallSegment[51]->setPos(Vec3(-4.0f, 36.0f, -10.0f));
	wallSegment[52]->setPos(Vec3(0.0f, 36.0f, -10.0f));
	//Right Offshoot Bottom Wall
	wallSegment[53]->setPos(Vec3(4.0f, 20.0f, -10.0f));
	wallSegment[54]->setPos(Vec3(6.0f, 20.0f, -10.0f));
	wallSegment[55]->setPos(Vec3(8.0f, 20.0f, -10.0f));
	wallSegment[56]->setPos(Vec3(10.0f, 20.0f, -10.0f));
	wallSegment[57]->setPos(Vec3(12.0f, 20.0f, -10.0f));
	//Right Offshoot Right Wall
	wallSegment[58]->setPos(Vec3(12.0f, 22.0f, -10.0f));
	wallSegment[59]->setPos(Vec3(12.0f, 24.0f, -10.0f));
	//Right Offshoot Top Wall
	wallSegment[60]->setPos(Vec3(4.0f, 26.0f, -10.0f));
	wallSegment[61]->setPos(Vec3(6.0f, 26.0f, -10.0f));
	wallSegment[62]->setPos(Vec3(8.0f, 26.0f, -10.0f));
	wallSegment[63]->setPos(Vec3(10.0f, 26.0f, -10.0f));
	wallSegment[64]->setPos(Vec3(12.0f, 26.0f, -10.0f));
	//floor
	wallSegment[92]->setPos(Vec3(-4.0f, 16.0f, -12.0f));
	wallSegment[93]->setPos(Vec3(-2.0f, 16.0f, -12.0f));
	wallSegment[94]->setPos(Vec3(0.0f, 16.0f, -12.0f));
	wallSegment[95]->setPos(Vec3(-4.0f, 18.0f, -12.0f));
	wallSegment[96]->setPos(Vec3(-2.0f, 18.0f, -12.0f));
	wallSegment[97]->setPos(Vec3(0.0f, 18.0f, -12.0f));
	wallSegment[98]->setPos(Vec3(-4.0f, 20.0f, -12.0f));
	wallSegment[99]->setPos(Vec3(-2.0f, 20.0f, -12.0f));
	wallSegment[100]->setPos(Vec3(0.0f, 20.0f, -12.0f));
	wallSegment[101]->setPos(Vec3(-4.0f, 22.0f, -12.0f));
	wallSegment[102]->setPos(Vec3(-2.0f, 22.0f, -12.0f));
	wallSegment[103]->setPos(Vec3(0.0f, 22.0f, -12.0f));
	wallSegment[104]->setPos(Vec3(2.0f, 22.0f, -12.0f));
	wallSegment[105]->setPos(Vec3(4.0f, 22.0f, -12.0f));
	wallSegment[106]->setPos(Vec3(6.0f, 22.0f, -12.0f));
	wallSegment[107]->setPos(Vec3(8.0f, 22.0f, -12.0f));
	wallSegment[108]->setPos(Vec3(10.0f, 22.0f, -12.0f));
	wallSegment[109]->setPos(Vec3(-4.0f, 24.0f, -12.0f));
	wallSegment[110]->setPos(Vec3(-2.0f, 24.0f, -12.0f));
	wallSegment[111]->setPos(Vec3(0.0f, 24.0f, -12.0f));
	wallSegment[112]->setPos(Vec3(2.0f, 24.0f, -12.0f));
	wallSegment[113]->setPos(Vec3(4.0f, 24.0f, -12.0f));
	wallSegment[114]->setPos(Vec3(6.0f, 24.0f, -12.0f));
	wallSegment[115]->setPos(Vec3(8.0f, 24.0f, -12.0f));
	wallSegment[116]->setPos(Vec3(10.0f, 24.0f, -12.0f));
	wallSegment[117]->setPos(Vec3(-4.0f, 26.0f, -12.0f));
	wallSegment[118]->setPos(Vec3(-2.0f, 26.0f, -12.0f));
	wallSegment[119]->setPos(Vec3(0.0f, 26.0f, -12.0f));
	wallSegment[120]->setPos(Vec3(-4.0f, 28.0f, -12.0f));
	wallSegment[121]->setPos(Vec3(-2.0f, 28.0f, -12.0f));
	wallSegment[122]->setPos(Vec3(0.0f, 28.0f, -12.0f));
	wallSegment[123]->setPos(Vec3(-4.0f, 30.0f, -12.0f));
	wallSegment[124]->setPos(Vec3(-2.0f, 30.0f, -12.0f));
	wallSegment[125]->setPos(Vec3(0.0f, 30.0f, -12.0f));
	wallSegment[126]->setPos(Vec3(-4.0f, 32.0f, -12.0f));
	wallSegment[127]->setPos(Vec3(-2.0f, 32.0f, -12.0f));
	wallSegment[128]->setPos(Vec3(0.0f, 32.0f, -12.0f));
	wallSegment[129]->setPos(Vec3(-4.0f, 34.0f, -12.0f));
	wallSegment[130]->setPos(Vec3(-2.0f, 34.0f, -12.0f));
	wallSegment[131]->setPos(Vec3(0.0f, 34.0f, -12.0f));
	wallSegment[132]->setPos(Vec3(-2.0f, 36.0f, -12.0f));


	//Inactive Glitch at (10.0f, 23.0f, -10.0f)
	doors[0]->setPos(Vec3(-2.0f, 36.0f, -10.0f));

	//Tutorial Level Set Up End, total number of blocks used 132, total number of doors used 1, total number of glitch used 1

	lightSource = Vec3(0.0, 0.0, -10.0);

	return true;
}

void The_Glitch::OnDestroy() {
	if (camera) delete camera, camera = nullptr;
	if (meshPtr1) delete meshPtr1, meshPtr1 = nullptr;
	if (meshPtr2) delete meshPtr2, meshPtr2 = nullptr;
	if (meshPtr3) delete meshPtr3, meshPtr3 = nullptr;
	if (texturePtr) delete texturePtr, texturePtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	if (playerModel) delete playerModel, playerModel = nullptr;
	for (int i = 0; i < numWalls; i++) {
		if (wallSegment[i]) delete wallSegment[i], wallSegment[i] = nullptr;
	}
	for (int i = 0; i < numDoors; i++) {
		if (doors[i]) delete doors[i], doors[i] = nullptr;
	}
	if (levelGen) delete levelGen, levelGen = nullptr;
}

void The_Glitch::HandleEvents(const SDL_Event& sdlEvent) {

	if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_W) {
		playerModel->setModelMatrix(MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::scale(0.4f, 0.4f, 0.4f));

		for (int i = 0; i < numWalls; i++) {
			wallSegment[i]->setVel(Vec3(0.0f, -15.0f, 0.0f));
			Physics::SimpleNewtonMotion(*wallSegment[i], deltaTime);
			wallSegment[i]->setModelMatrix(MMath::translate(wallSegment[i]->getPos()));
			
		}
		for (int i = 0; i < numDoors; i++) {
			doors[i]->setVel(Vec3(0.0f, -15.0f, 0.0f));
			Physics::SimpleNewtonMotion(*doors[i], deltaTime);
			doors[i]->setModelMatrix(MMath::translate(doors[i]->getPos()));
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
		for (int i = 0; i < numDoors; i++) {
			doors[i]->setVel(Vec3(15.0f, 0.0f, 0.0f));
			Physics::SimpleNewtonMotion(*doors[i], deltaTime);
			doors[i]->setModelMatrix(MMath::translate(doors[i]->getPos()));
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
		for (int i = 0; i < numDoors; i++) {
			doors[i]->setVel(Vec3(0.0f, 15.0f, 0.0f));
			Physics::SimpleNewtonMotion(*doors[i], deltaTime);
			doors[i]->setModelMatrix(MMath::translate(doors[i]->getPos()));
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
		for (int i = 0; i < numDoors; i++) {
			doors[i]->setVel(Vec3(-15.0f, 0.0f, 0.0f));
			Physics::SimpleNewtonMotion(*doors[i], deltaTime);
			doors[i]->setModelMatrix(MMath::translate(doors[i]->getPos()));
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

		
		for (int i = 0; i < numDoors; i++) {
			Vec3 temp = doors[i]->getPos();
			if (temp.y <= 2.0f && temp.x <= 2.0f && temp.y >= -2.0f && temp.x >= -2.0f) {
				Debug::Info("Door State Changed", __FILE__, __LINE__);
				doors[i]->openCloseDoor();
				if (doors[i]->getOpenState()) {
					Debug::Info("Room Created", __FILE__, __LINE__);
					levelGen->RoomPlacement(doors[i]->getDirection(), doors[i]->getPos(), wallSegment[0], doors[0] , i);
				}
			}
		}
		//interact
	}

}

void The_Glitch::Update(const float deltaTime_) {
	deltaTime = deltaTime_;
	playerModel->Update(deltaTime_);

	for (int i = 0; i < numWalls; i++) {
		wallSegment[i]->Update(deltaTime_);
	}
	for (int i = 0; i < numDoors; i++) {
		doors[i]->Update(deltaTime_);
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
	for (int i = 0; i < numDoors; i++) {
		glUniformMatrix4fv(doors[i]->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
		glUniformMatrix4fv(doors[i]->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix());
		glUniform3fv(doors[i]->getShader()->getUniformID("lightPos"), 1, lightSource);
	}


	playerModel->Render();

	for (int i = 0; i < numWalls; i++) {
			wallSegment[i]->Render();
	}
	for (int i = 0; i < numDoors; i++) {
		doors[i]->Render();
	}

	glUseProgram(0);
}