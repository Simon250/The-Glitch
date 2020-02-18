#ifndef CAMERA_H
#define CAMERA_H
#include "Vector.h"
#include "Matrix.h"
#include "SkyBox.h"

using namespace MATH;
class Camera : public GameObject{
private:

	Matrix4 projection;
	Matrix4 rotate;
	Matrix4 translate;
	Matrix4 view;
	SkyBox *skyBox;

public:
	inline bool OnCreate() { return true; }
	inline void OnDestroy() {}
	void Update(const float deltaTime);
	void HandleEvents(const SDL_Event& event);
	void Render() const;
	inline Matrix4 getProjectionMatrix() const { return projection; }
	inline Matrix4 getViewMatrix() const { return rotate * translate; }
	inline void setProjectionMatrix(Matrix4 projection_){ projection = projection_; }
	//inline void setViewMatrix(Matrix4 view_) { view = view_;  }
	inline void setSkyBox(SkyBox* skyBox_) { skyBox = skyBox_; }
	Camera();
	~Camera();
};

#endif



