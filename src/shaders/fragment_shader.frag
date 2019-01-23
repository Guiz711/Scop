#version 410 core
out vec4 FragColor;
in vec3 ourColor;

uniform float test;

void main()
{
	FragColor = vec4(ourColor, 1.0f);
}
