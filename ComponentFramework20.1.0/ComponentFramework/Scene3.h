#ifndef SCENE3_H
#define SCENE3_H
#include "Scene.h"
#include "Vector.h"
using namespace MATH;

union SDL_Event;
class Camera;
class DemoObject;
class Mesh;
class Shader;
class Texture;
class SkyBox;

class Scene3 : public Scene {
private:
	Camera* camera;
	DemoObject* demoObject;
	Vec3 lightSource;
	Mesh* meshPtr;
	Shader* shaderPtr;
	Texture* texturePtr;
	SkyBox* skyBox;
public:
	explicit Scene3();
	virtual ~Scene3();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event& sdlEvent) override;
};


#endif // SCENE3_H