#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "window.h"
#include "main_init.h"
#include "main_destroy.h"
#include "renderer/renderer.h"
#include "renderer/renderable/sprite_renderable.h"
#include "resource_loader/resource_loader.h"
#include "renderer/texture_2d.h"

#define TITLE "Spinneret"

int width = 800;
int height = 600;

void render(Window& window, Renderer& renderer) {
	renderer.clear();
	renderer.draw();

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

	ResourceLoader::init();
	Renderer renderer;
	SpriteRenderable spriteRenderable("base", "container");
	renderer.addRenderable(spriteRenderable);

	while (!window.shouldClose()) {
		window.processInput();
		render(window, renderer);
		window.pollInput();
	}

	destroyGlfw();

	return 0;
}