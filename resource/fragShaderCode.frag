#version 330 core
in vec4 vertexColor;
in vec2 ourTexCord;

out vec4 FragColor;

uniform sampler2D ourTexture;
uniform sampler2D Smlie;
uniform float Mix;


void main()
{
	float Nx = -ourTexCord.x;
	vec2 NTexCord = vec2(Nx,ourTexCord.y);
	FragColor =  mix(texture(ourTexture,ourTexCord),texture(Smlie,NTexCord),Mix);
}