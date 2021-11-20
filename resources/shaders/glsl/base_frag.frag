#version 330 core

in vec2 uv;

out vec4 color;

uniform sampler2D mainTex;
uniform sampler2D secondTex;

void main() {
	//color = vec4(1.0f, 0.5f, 0.0f, 1.0f);
	//color = texture(mainTex, uv);
	color = mix(texture(mainTex, uv), texture(secondTex, uv), 0.2);
}