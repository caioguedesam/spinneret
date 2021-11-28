#include "display/display.h"
#include "logs.h"

Display::~Display()
{
	if (_window) {
		SDL_DestroyWindow(_window);
	}
}

void Display::init()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

int Display::createWindowAndContext(const uint& width, const uint& height, const char* windowTitle)
{
	// Creates new window
	_window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (!_window) {
		logError("DISPLAY_WINDOW", "Couldn't create new SDL window");
		return 0;
	}

	// Creates new OpenGL context for the new window
	if (!makeContext()) {
		return 0;
	}

	return 1;
}

int Display::makeContext()
{
	if (!_window) {
		logError("DISPLAY_OPENGL_CONTEXT", "Can't create context for null window");
		return 0;
	}
	_context = SDL_GL_CreateContext(_window);
	if (!_context) {
		logError("DISPLAY_OPENGL_CONTEXT", "Couldn't create new OpenGL context");
		return 0;
	}
	return 1;
}

void Display::swapWindowBuffers() const
{
	SDL_GL_SwapWindow(_window);
}

void Display::setViewport(const uint& width, const uint& height) const
{
	glViewport(0, 0, width, height);
}
