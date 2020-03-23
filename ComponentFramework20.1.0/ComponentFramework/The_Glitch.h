#ifndef THE_GLITCH
#define THE_GLITCH
#include "Vector.h"
#include "Scene.h"
#include "Plane.h"
#include "WallSegment.h"
#include "Door.h"

using namespace MATH;

/// Forward declarations 
union SDL_Event;
class Camera;
class DemoObject;
class Mesh;
class Shader;
class Texture;

class The_Glitch : public Scene
{
	friend class Level1Gen;
private:
	Camera *camera;
	DemoObject *playerModel;
	WallSegment *wallSegment[165];
	int numWalls;
	Vec3 lightSource;
	Mesh *meshPtr1;
	Mesh *meshPtr2;
	Shader *shaderPtr;
	Texture *texturePtr;
	float playerSpeed;
	float deltaTime;
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