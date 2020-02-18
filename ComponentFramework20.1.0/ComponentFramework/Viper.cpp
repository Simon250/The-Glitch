#include "Viper.h"
#include "Physics.h"
#include "MMath.h"

Viper::Viper(Mesh* mesh_, Shader* shader_, Texture* texture_) :
	mesh(mesh_), shader(shader_), texture(texture_) {

	modelMatrixID = shader->getUniformID("modelMatrix");
	normalMatrixID = shader->getUniformID("normalMatrix");
}

Viper::~Viper() {}

bool Viper::OnCreate() { return true; } /// Just a stub
void Viper::OnDestroy() {}				  /// Just a stub
void Viper::Update(float deltaTime_) {
	curTime += deltaTime_;

	if (curTime < 3.0f) {

		this->applyForce(Vec3(1.0f, 0.0f, 0.0f));
		Physics::SimpleNewtonMotion(*this, deltaTime_);
		this->setModelMatrix(MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::translate(pos));
	}
	else if (curTime < 5.0f) {


		this->applyForce(MMath::rotate(angle, Vec3(0.0, 1.0, 0.0)) * Vec3(2.0f, 0.0f, 0.0f));
		this->applyTorque(25.0f);
		Physics::SimpleNewtonMotion(*this, deltaTime_);
		Physics::RigidBodyRotation(*this, deltaTime_);
		this->setModelMatrix(MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::translate(pos)* MMath::rotate(angle, Vec3(0.0f, 1.0f, 0.0f)));
	}
	else {

		angAccel = 0.0f;
		accel = Vec3(0.0f);
		Physics::SimpleNewtonMotion(*this, deltaTime_);
		Physics::RigidBodyRotation(*this, deltaTime_);
		this->setModelMatrix(MMath::rotate(90.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::translate(pos) * MMath::rotate(angle, Vec3(0.0f, 1.0f, 0.0f)));
	
	}


}

void Viper::Render() const {

	/// This is some fancy code.  Assigning a 4x4 matrix to a 3x3 matrix
	/// just steals the upper 3x3 of the 4x4 and assigns thoses values 
	/// to the 3x3.  
	Matrix3 normalMatrix = MMath::transpose(MMath::inverse(modelMatrix));

	glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, modelMatrix);
	glUniformMatrix3fv(normalMatrixID, 1, GL_FALSE, normalMatrix);
	if (texture) {
		glBindTexture(GL_TEXTURE_2D, texture->getTextureID());
	}

	mesh->Render();

	/// Unbind the texture
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Viper::HandleEvents(const SDL_Event& event) {} /// Just a stub