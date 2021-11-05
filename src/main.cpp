#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "window.h"
#include "main_init.h"
#include "main_destroy.h"
#include "renderer/vertex_buffer.h"
#include "renderer/shader.h"

#define TITLE "Spinneret"

int width = 800;
int height = 600;

float vertices[] = {
	 0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
};

void setupRender() {
	glEnable(GL_DEPTH_TEST);
}

void render(Window& window) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// use shader
	// draw polygon

	window.swapBuffers();
}

int main(int argc, char* argv[]) {
	std::cout << sizeof(vertices) << std::endl;
	initializeGlfw();

	Window window;
	if (!initializeWindowAndContext(&window, width, height, TITLE)) {
		return -1;
	}
	if (!initializeGlad()) {
		return -1;
	}

	setupRender();
	Shader baseShader("resources\\shaders\\base_vert.vert", "resources\\shaders\\base_frag.frag");
	baseShader.use();

	while (!window.shouldClose()) {
		window.processInput();
		render(window);
		window.pollInput();
	}

	destroyGlfw();

	return 0;
}