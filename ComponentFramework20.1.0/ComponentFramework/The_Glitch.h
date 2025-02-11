#ifndef THE_GLITCH
#define THE_GLITCH
#include "Vector.h"
#include "Scene.h"
#include "Plane.h"
#include "WallSegment.h"
#include "Door.h"
#include "Level1Gen.h"

using namespace MATH;

/// Forward declarations 
union SDL_Event;
class Camera;
class DemoObject;
class Mesh;
class Shader;
class Texture;
class Door;

class The_Glitch : public Scene
{
	friend class Level1Gen;
private:
	Camera *camera;
	DemoObject *playerModel;
	WallSegment *wallSegment[165];
	Door *doors[10];
	int numWalls;
	int numDoors;
	Vec3 lightSource;
	Mesh *meshPtr1;
	Mesh *meshPtr2;
	Mesh* meshPtr3;
	Shader *shaderPtr;
	Texture *texturePtr;
	float playerSpeed;
	float deltaTime;
	Level1Gen *levelGen;
public:
	explicit The_Glitch();
	virtual ~The_Glitch();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime_) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event& sdlEvent) override;

};

#endif