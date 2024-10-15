#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform vec4 u_Tint;
uniform mat4 u_MVP;

out vec4 vertexColor;
out vec2 TexCoord;

void main()
{
	gl_Position = u_MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);
	vertexColor = u_Tint * aColor;
    TexCoord = aTexCoord;
}
