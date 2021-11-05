#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "window.h"
#include "main_init.h"
#include "main_destroy.h"

#define TITLE "Spinneret"

int width = 800;
int height = 600;

void setupRender() {
	glEnable(GL_DEPTH_TEST);
}

void render(Window& window) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

	while (!window.shouldClose()) {
		window.processInput();
		render(window);
		window.pollInput();
	}

	destroyGlfw();

	return 0;
}