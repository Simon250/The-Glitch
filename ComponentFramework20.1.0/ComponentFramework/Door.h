#ifndef DOOR_H
#define DOOR_H

#include "GameObject.h"
#include "PhysicsObject.h"

class Door : public GameObject, public PhysicsObject
{
	Vec3 pos;
	float direction;
	float curRoom;

	bool openState;
	bool isRendered;

	bool openCloseDoor(bool openState_);

	Door(Vec3 pos_, bool isRendered_, float direction_, float curRoom_);
	~Door();

	bool OnCreate() override;
	void OnDestroy() override;
	void HandleEvents(const SDL_Event &event) override;
	void Update(const float deltaTime) override;
	void Render()const override;
};

#endif