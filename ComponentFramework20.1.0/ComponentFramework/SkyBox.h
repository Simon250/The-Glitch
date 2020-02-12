#ifndef SKYBOX_H
#define SKYBOX_H
#include <glew.h>
#include "GameObject.h"
#include "Debug.h"
#include "MMath.h"
#include "Shader.h"

union SDL_Event;
class DemoObject;
class Mesh;
class Shader;
class Texture;

class SkyBox : public GameObject
{

private:
	GLuint skyBoxTextureID;
	bool loadSkyBoxTextures(const char* posX, const char* negX, const char* posY, const char* negY, const char* posZ, const char* negZ);
	DemoObject* demoObject;
	Mesh* meshPtr;
	Shader* shaderPtr;
	Texture* texturePtr;
public:
	inline Shader* getShader() { return shaderPtr; }
	void Render() const;
	bool OnCreate();
	void OnDestroy();
	void Update(const float deltaTime);
	void HandleEvents(const SDL_Event& event);
};
#endif