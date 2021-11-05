#include "main_init.h"
#include "main_destroy.h"
#include <iostream>

void glfwErrorCallback(int error, const char* description) {
	std::cout << "ERROR::GLFW::" << description << std::endl;
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
		std::cout << "Failed to initialize GLAD" << std::endl;
		return 0;
	}
	return 1;
}