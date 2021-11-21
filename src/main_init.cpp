#include "main_init.h"
#include "main_destroy.h"
#include <iostream>
#include "logs.h"

void glfwErrorCallback(int error, const char* description) {
	logError("GLFW_ON_ERROR", description);
}

void initializeGlfw() {
	glfwSetErrorCallback(glfwErrorCallback);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int initializeWindowAndContext(Window* window, const uint& width, const uint& height, const char* title) {
	if (!window->init(width, height, title)) {
		destroyGlfw();
		return 0;
	}
	window->makeContextCurrent();
	return 1;
}

int initializeGlad() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		logError("GLAD", "failed to initialize GLAD");
		return 0;
	}
	return 1;
}