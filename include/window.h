#pragma once
#include "gl_includes.h"
#include "typedefs.h"

class Window {
private:
	GLFWwindow* _windowObj;
public:
	int init(const uint& width, const uint& height, const char* windowTitle);
	
	void makeContextCurrent();
	void setFramebufferSizeCallback(GLFWframebuffersizefun callback);
	bool shouldClose();
	void swapBuffers();
	void pollInput();
	void processInput();

	inline GLFWwindow* getObject() { return _windowObj; }
};

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
