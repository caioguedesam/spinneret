#include <iostream>

#include <SDL.h>

#include "main_init.h"
#include "display/display.h"
#include "renderer/renderer.h"
#include "renderer/renderable/sprite_renderable.h"
#include "resource_loader/resource_loader.h"

#define TITLE "Spinneret"

int width = 800;
int height = 600;

bool isRunning = true;

void render(Display& display, Renderer& renderer) {
	renderer.clear();
	renderer.draw();

	display.swapWindowBuffers();
}

void handleKeyPressEvent(SDL_Keysym& key, Camera2D* camera) {
	glm::vec3 cameraPos = camera->getPosition();
	float cameraAngle = camera->getAngle();
	const float cameraSpeed = 2.25f;
	switch (key.sym) {
	// Camera movement
	case SDLK_UP:
		camera->moveTo(cameraPos + cameraSpeed * glm::vec3(0.f, 1.f, 0.f));
		break;
	case SDLK_DOWN:
		camera->moveTo(cameraPos - cameraSpeed * glm::vec3(0.f, 1.f, 0.f));
		break;
	case SDLK_LEFT:
		camera->moveTo(cameraPos - cameraSpeed * glm::vec3(1.f, 0.f, 0.f));
		break;
	case SDLK_RIGHT:
		camera->moveTo(cameraPos + cameraSpeed * glm::vec3(1.f, 0.f, 0.f));
		break;
	// Camera rotation
	case SDLK_a:
		camera->rotateTo(cameraAngle - 0.5f);
		break;
	case SDLK_d:
		camera->rotateTo(cameraAngle + 0.5f);
		break;
	// Quit application
	case SDLK_ESCAPE:
		isRunning = false;
		break;
	}
}

// TODO: not permanent event solution, only for testing purposes
void pollEvents(Camera2D* camera) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			handleKeyPressEvent(event.key.keysym, camera);
		}
	}
}

int main(int argc, char* argv[]) {
	if (!initSDL()) {
		return -1;
	}

	Display display;
	display.init();
	if (!display.createWindowAndContext(width, height, TITLE)) {
		return -1;
	}

	if (!initGlad()) {
		return -1;
	}

	ResourceLoader::init();
	Renderer renderer;
	Camera2D camera((float)width, (float)height, 0.1f, 100.f);
	camera.moveTo(0.f, 0.f, -10.f);
	renderer.setCamera(camera);

	SpriteRenderable spriteRenderable("base");
	spriteRenderable.setTexture("container", 0);
	spriteRenderable.setTexture("awesome", 1);
	renderer.addRenderable(spriteRenderable);

	while (isRunning) {
		pollEvents(&camera);
		render(display, renderer);
	}

	SDL_Quit();
	return 0;
}