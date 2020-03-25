#include "Collider.h"

bool Collider::CollisionDetection(static DemoObject* playerObject, static DemoObject* wallObject)
{
	if (playerObject->distance(wallObject) <= 10.12)
	{
		return true;
	}
	return false;
}