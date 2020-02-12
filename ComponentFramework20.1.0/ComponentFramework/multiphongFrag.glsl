#version 450
in  vec3 vertNormal;
in  vec3 lightDir[2];
in  vec3 eyeDir;
out vec4 fragColor;

void main() { 
	vec4 ks[2] = vec4[] (vec4(0.0, 0.6, 0.6, 0.0), vec4(0.4, 0.0, 0.4, 0.0) );
	vec4 kd[2] = vec4[] (vec4(0.0, 0.6, 0.6, 0.0), vec4(0.6, 0.0, 0.6, 0.0) );
	vec4 ka = 0.1 * kd[0] * kd[1];

	float diff[2];
	float spec[2];
	vec3 reflection[2];

	/// Reflection is based incedent which means a vector from the light source
	/// not the direction to the light source

	for(int i = 0; i < 2; i++){
	diff[i] = max(dot(vertNormal, lightDir[i]), 0.0);
	reflection[i] = normalize(reflect(-lightDir[i], vertNormal));
	spec[i] = max(dot(eyeDir, reflection[i]), 0.0);
	if(diff[i] > 0.0){
		spec[i] = pow(spec[i], 14.0);
	}
	}
	
	fragColor =  ka + ((diff[0] * kd[0]) + (diff[1] * kd[1]) + (spec[0] * ks[0]) + (spec[1] * ks[1]))/2;	
} 

