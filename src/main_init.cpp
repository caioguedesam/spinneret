#include "main_init.h"
#include "logs.h"
#include "SDL.h"

int initSDL() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1) {
		return 0;
	}
	SDL_GL_LoadLibrary(NULL);
	return 1;
}

int initGlad() {
	if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
		logError("GLAD", "failed to initialize GLAD");
		return 0;
	}
	return 1;
}