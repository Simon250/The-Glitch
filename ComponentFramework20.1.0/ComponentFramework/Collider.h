#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>

#include "PhysicsObject.h"
#include "DemoObject.h"

static struct Collider
{
	static bool CollisionDetection(static DemoObject* playerObject, static DemoObject* wallObject);

	static DemoObject* FindClosestObject(static DemoObject* playerObject, static DemoObject* objectArray[], static float direction);
};

#endif