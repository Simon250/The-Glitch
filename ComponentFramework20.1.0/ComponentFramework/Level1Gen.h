#ifndef LEVEL1GEN
#define LEVEL1GEN
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
#include "WallSegment.h"

class WallSegment;

class Level1Gen
{
public:
	Level1Gen();
	~Level1Gen();

	int RoomGenerations();
	void RoomPlacement(Vec3 d, Vec3 doorPoss, WallSegment* wallSegment);
	
private:
	float curRoom;
	int seed;
	long ran1idnum;
	int roomsgen[101];
	int roomsBlockNum[101];
	Vec3 room1[29];
	Vec3 room2[54];
	Vec3 room3[25];
	Vec3 room4[30];
};
#endif
