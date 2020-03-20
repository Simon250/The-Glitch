#include "Door.h"

Door::Door(Vec3 pos_, bool isRendered_, float direction_, float curRoom_)
{
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;

	curRoom = curRoom_;
	direction = direction_;
	openState = false;
	isRendered = isRendered_;
}

bool Door::openCloseDoor(bool openState_)
{
	if (openState_ == false)
	{
		openState = true;
	}
	else
	{
		openState = false;
	}

	return openState;
}

bool Door::OnCreate()
{
	return true;
}

void Door::OnDestroy()
{

}

void Door::HandleEvents(const SDL_Event& event)
{

}

void Door::Update(const float deltaTime)
{

}

void Door::Render()const
{
	if (isRendered == true)
	{

	}
	else
	{

	}
}

Door::~Door()
{

}