#ifndef WALLSEGMENT
#define WALLSEGMENT
#include "GameObject.h"
#include "PhysicsObject.h"
#include "Level1Gen.h"
#include "MMath.h"

using namespace MATH;


class WallSegment : public GameObject, public PhysicsObject {

friend class Level1Gen;

private:
	Matrix4 modelMatrix;
	GLuint modelMatrixID;
	GLuint normalMatrixID;
	Mesh* mesh;
	Shader* shader;
	Texture* texture;
	bool isRend;
	int partOfRoom;
public:
	WallSegment(Mesh* mesh_, Shader* shader_, Texture* texture_);
	~WallSegment();

	bool OnCreate();
	void OnDestroy();
	void Update(const float deltaTime);
	void Render() const;
	void HandleEvents(const SDL_Event& event);

	inline Shader* getShader() const { return shader; }
	inline void setModelMatrix(const Matrix4& modelMatrix_) { modelMatrix = modelMatrix_; }
	inline const Matrix4& getModelMatrix() { return modelMatrix; }

};
#endif

