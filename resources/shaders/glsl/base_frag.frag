#version 330 core

in vec2 uv;

out vec4 color;

uniform sampler2D tex_0;
uniform sampler2D tex_1;

void main() {
	//color = vec4(1.0f, 0.5f, 0.0f, 1.0f);
	//color = texture(tex_0, uv);
	color = mix(texture(tex_0, uv), texture(tex_1, uv), 0.2);
}