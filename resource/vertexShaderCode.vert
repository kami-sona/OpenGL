#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCord;

out vec4 vertexColor;
out vec2 ourTexCord;
uniform mat4 model;
uniform mat4 view;
uniform mat4 project;

void main()
{
	gl_Position =  project * view * model * vec4(aPos,1.0);
	ourTexCord = aTexCord;
	vertexColor = vec4(aColor,1.0);
}