#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "window.h"
#include "main_init.h"
#include "main_destroy.h"
#include "renderer/renderer.h"
#include "renderer/renderable/basic_renderable.h"

#define TITLE "Spinneret"

int width = 800;
int height = 600;

// TODO: vertices are in normalized device coordinates. Must update base shader
// to use MVP matrix and change these to object space.
float vertices[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
};

uint indices[] = {
	0, 1, 3,
	1, 2, 3
};

void render(Window& window, Renderer& renderer) {
	renderer.clear();
	renderer.draw();

	window.swapBuffers();
}

int main(int argc, char* argv[]) {
	initializeGlfw();

	Window window;
	if (!initializeWindowAndContext(&window, width, height, TITLE)) {
		return -1;
	}
	if (!initializeGlad()) {
		return -1;
	}

	Shader baseShader("resources\\shaders\\base_vert.vert", "resources\\shaders\\base_frag.frag");

	VertexArray va;
	VertexBuffer vb(vertices, sizeof(vertices));
	IndexBuffer ib(indices, sizeof(indices));
	VertexBufferLayout layout;

	layout.push<float>(3);
	va.addBuffer(vb, layout);

	Renderer renderer;
	renderer.init();
	BasicRenderable renderable(va, ib, baseShader);
	renderer.addRenderable(renderable);

	while (!window.shouldClose()) {
		window.processInput();
		render(window, renderer);
		window.pollInput();
	}

	destroyGlfw();

	return 0;
}