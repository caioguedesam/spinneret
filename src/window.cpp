#include "window.h"
#include <iostream>

int Window::init(const uint& width, const uint& height, const char* windowTitle)
{
	_windowObj = glfwCreateWindow(width, height, windowTitle, NULL, NULL);
	if (_windowObj == NULL) {
		return 0;
	}
	setFramebufferSizeCallback(framebufferSizeCallback);
	return 1;
}

void Window::makeContextCurrent()
{
	glfwMakeContextCurrent(_windowObj);
}

void Window::setFramebufferSizeCallback(GLFWframebuffersizefun callback)
{
	glfwSetFramebufferSizeCallback(_windowObj, callback);
}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(_windowObj);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(_windowObj);
}

void Window::pollInput()
{
	glfwPollEvents();
}

void Window::processInput()
{
	// using GLFW input
	if (glfwGetKey(_windowObj, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(_windowObj, true);
	}
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
