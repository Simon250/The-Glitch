#include "Door.h"

Door::Door(Mesh* mesh_, Shader* shader_, Texture* texture_):
	mesh(mesh_), shader(shader_), texture(texture_) {
		isRendered = true;
		partOfRoom = -1;
		modelMatrixID = shader->getUniformID("modelMatrix");
		normalMatrixID = shader->getUniformID("normalMatrix");
		openState = false;
}

bool Door::openCloseDoor()
{
	if (openState == false)
	{
		openState = true;
	}
	else
	{
		openState = false;
	}

	return openState;
}

bool Door::OnCreate()
{
	return true;
}

void Door::OnDestroy()
{

}

void Door::HandleEvents(const SDL_Event& event)
{

}

void Door::Update(const float deltaTime)
{
	if (pos.x > 6.2 || pos.y > 6.2 || pos.x < -6.2 || pos.y < -6.2) {
		isRendered = false;
	}
	else {
		isRendered = true;
	}

	this->setModelMatrix(MMath::translate(pos) * MMath::rotate(0.0f, Vec3(1.0f, 0.0f, 0.0f)) * MMath::scale(1.0f, 0.5f, 2.0f));
}

void Door::Render()const
{
	if (isRendered) {
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

Door::~Door()
{

}