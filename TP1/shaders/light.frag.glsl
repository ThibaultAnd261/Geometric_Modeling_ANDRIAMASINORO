#version 120

varying vec4 myvertex;
varying vec3 mynormal;

uniform mat3 mynormal_matrix;
uniform mat4 myview_matrix;
uniform int type;
uniform vec4 kd;

void main() {
	vec3 eyepos = vec3(0,0,0);
	vec3 mypos = vec3(myview_matrix * myvertex);
	vec3 normal = normalize(mynormal_matrix * mynormal);

	vec3 lightpos = vec3(0, 0, 4);
	vec3 lightdir = normalize(lightpos - mypos);
	vec3 eyedir = normalize(eyepos - mypos);
	vec3 reflectdir = reflect(-lightdir, normal);

	vec4 mylight_color = vec4(1,1,1,0);
	vec4 finalcolor = vec4(0.1,0.1,0.1,0) +
		kd * mylight_color * max(dot(lightdir, normal), 0.0) +
		kd * mylight_color * pow(max(dot(reflectdir, eyedir), 0.0), 60.0);

	if (type == 1) finalcolor = kd;
	gl_FragColor = finalcolor;
}
