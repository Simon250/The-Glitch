#ifndef SCENE2_H
#define SCENE2_H
#include "Scene.h"
#include "Vector.h"
using namespace MATH;

union SDL_Event;
class Camera;
class DemoObject;
class Mesh;
class Shader;
class Texture;
class Scene2 : public Scene {

private:
	Camera* camera;
	DemoObject* orbObj[4];
	Vec3 lightSource;
	Mesh* meshPtr;
	Shader* shaderPtr;
	Texture* texturePtr;
	Texture* marsTextPtr;
	Texture* moonTextPtr;
	Texture* marioTextPtr;
public:
	explicit Scene2();
	virtual ~Scene2();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
};


#endif // SCENE2_H