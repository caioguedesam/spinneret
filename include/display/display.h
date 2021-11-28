#pragma once

#include "SDL.h"
#include "typedefs.h"
#include "gl_includes.h"

class Display
{
private:
	SDL_Window* _window;
	SDL_GLContext _context;
public:
	~Display();

	static void init();
	int createWindowAndContext(const uint& width, const uint& height, const char* windowTitle);
	int makeContext();

	void swapWindowBuffers() const;
	void setViewport(const uint& width, const uint& height) const;
};