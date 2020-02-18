#version 450
in vec3 textureCoords;

out vec4 fragColor;
uniform samplerCube skyBoxTexture;


void main() {
	vec3 textCoordsInvX = textureCoords;
	textCoordsInvX.x *= -1.0;
	fragColor =  texture(skyBoxTexture, textCoordsInvX); 
}