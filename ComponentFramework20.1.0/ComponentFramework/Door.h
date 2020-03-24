#ifndef DOOR_H
#define DOOR_H

#include "GameObject.h"
#include "PhysicsObject.h"
#include "MMath.h"
#include "Level1Gen.h"

using namespace MATH;

class Door : public GameObject, public PhysicsObject
{

friend class Level1Gen;

protected:
	Matrix4 modelMatrix;
	GLuint modelMatrixID;
	GLuint normalMatrixID;
	Mesh* mesh;
	Shader* shader;
	Texture* texture;
	Vec3 direction;

	int RoomGenerated;
	int partOfRoom;
	bool openState;
	bool isRendered;

	

public:

	
	Door(Mesh* mesh_, Shader* shader_, Texture* texture_);
	~Door();

	inline bool getOpenState() { return openState; }
	bool openCloseDoor();
	bool OnCreate() override;
	void OnDestroy() override;
	void HandleEvents(const SDL_Event &event) override;
	void Update(const float deltaTime) override;
	void Render()const override;

	inline Shader* getShader() const { return shader; }
	inline void setModelMatrix(const Matrix4& modelMatrix_) { modelMatrix = modelMatrix_; }
	inline const Matrix4& getModelMatrix() { return modelMatrix; }
};

#endif