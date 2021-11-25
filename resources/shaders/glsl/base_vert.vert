#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

out vec2 uv;

uniform mat4 u_mvp;

void main() {
	gl_Position = u_mvp * vec4(position, 1.0);
	uv = texCoord;
}