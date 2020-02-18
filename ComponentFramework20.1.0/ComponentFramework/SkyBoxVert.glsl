#version 450
layout (location = 0) in  vec4 vVertex;
layout (location = 1) in  vec4 vNormal;

out vec3 textureCoords;
uniform mat4 projectionMatrix;
uniform mat4 cameraRotationMatrix;


void main() {
	textureCoords = vec3(vVertex);
	gl_Position = projectionMatrix * cameraRotationMatrix * vVertex;
}
