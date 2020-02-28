#include "WallSegment.h"

#include "MMath.h"

WallSegment::WallSegment(Mesh* mesh_, Shader* shader_, Texture* texture_) :
	mesh(mesh_), shader(shader_), texture(texture_) {
	isRend = true;
	partOfRoom = -1;
	modelMatrixID = shader->getUniformID("modelMatrix");
	normalMatrixID = shader->getUniformID("normalMatrix");
}

WallSegment::~WallSegment() {}

bool WallSegment::OnCreate() { return true; } /// Just a stub
void WallSegment::OnDestroy() {}				  /// Just a stub
void WallSegment::Update(float deltaTime_) {

	if (pos.x > 20 || pos.y > 20 || pos.x < -20 || pos.y < -20) {
		isRend = false;
	}
	else {
		isRend = true;
	}

	this->setModelMatrix(MMath::rotate(0.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::scale(0.4f, 0.4f, 0.4f));

}

void WallSegment::Render() const {

	if (isRend) {
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
}

void WallSegment::HandleEvents(const SDL_Event& event) {} /// Just a stub
