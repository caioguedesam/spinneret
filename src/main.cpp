#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "window.h"
#include "main_init.h"
#include "main_destroy.h"
#include "renderer/vertex_array.h"
#include "renderer/index_buffer.h"
#include "renderer/shader.h"

#define TITLE "Spinneret"

int width = 800;
int height = 600;

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

void setupRender() {
	glEnable(GL_DEPTH_TEST);
}

void render(Window& window) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glDrawArrays(GL_TRIANGLES, 0, 3);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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

	setupRender();
	Shader baseShader("resources\\shaders\\base_vert.vert", "resources\\shaders\\base_frag.frag");
	baseShader.use();

	VertexArray va;
	VertexBuffer vb(vertices, sizeof(vertices));
	IndexBuffer ib(indices, sizeof(indices));
	VertexBufferLayout layout;

	layout.Push<float>(3);
	va.AddBuffer(vb, layout);
	va.Bind();

	while (!window.shouldClose()) {
		window.processInput();
		render(window);
		window.pollInput();
	}

	destroyGlfw();

	return 0;
}