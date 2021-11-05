#pragma once
#include <window.h>

void glfwErrorCallback(int error, const char* description);

void initializeGlfw();
int initializeWindowAndContext(Window* window, const uint& width, const uint& height, const char* title);
int initializeGlad();