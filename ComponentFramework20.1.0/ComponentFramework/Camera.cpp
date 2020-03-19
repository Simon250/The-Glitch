#include "Camera.h"
#include "MMath.h"

Camera::Camera() {
	setProjectionMatrix(MMath::perspective(60.0f, (16.0f / 9.0f), 0.5f, 120.0f));
	//setViewMatrix(MMath::lookAt(Vec3(0.0, 0.0, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f)));

	rotate = MMath::rotate(0.0f, Vec3(0.0f, 1.0f, 0.0f));
	translate = MMath::translate(Vec3(0.0f, 0.0f, -10.0f));

	view = rotate * translate;
}

Camera::~Camera() {}

void Camera::Update(const float deltaTime) {
}

void Camera::HandleEvents(const SDL_Event& event) {
}

void Camera::Render() const {
	if (skyBox) {
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_CULL_FACE);
		glUseProgram(skyBox->getShader()->getProgram());
		glUniformMatrix4fv(skyBox->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, projection);
		glUniformMatrix4fv(skyBox->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, rotate);
		glUniformMatrix4fv(skyBox->getShader()->getUniformID("modelMatrix"), 1, GL_FALSE, Matrix4());
		skyBox->Render();
		glUseProgram(0);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
	}
}

