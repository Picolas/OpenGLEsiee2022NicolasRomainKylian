#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aTexCoord;

out vec3 TexCoord;

uniform mat4 trs;
uniform mat4 camera;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f) * trs * camera;
	TexCoord = aTexCoord;
}
