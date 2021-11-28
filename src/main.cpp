//#include <SDL.h>
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

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#define TITLE "Spinneret"

int width = 800;
int height = 600;

void render(Window& window, Renderer& renderer) {
	renderer.clear();
	renderer.draw();

	window.swapBuffers();
}

//void handleKeyPressEvent(SDL_Keysym& key, Camera2D* camera) {
//	glm::vec3 cameraPos = camera->getPosition();
//	const float cameraSpeed = 0.25f;
//	switch (key.sym) {
//	case SDLK_UP:
//		camera->moveTo(cameraPos + cameraSpeed * glm::vec3(0.f, 1.f, 0.f));
//		break;
//	case SDLK_DOWN:
//		camera->moveTo(cameraPos - cameraSpeed * glm::vec3(0.f, 1.f, 0.f));
//		break;
//	case SDLK_LEFT:
//		camera->moveTo(cameraPos - cameraSpeed * glm::vec3(1.f, 0.f, 0.f));
//		break;
//	case SDLK_RIGHT:
//		camera->moveTo(cameraPos + cameraSpeed * glm::vec3(1.f, 0.f, 0.f));
//		break;
//	}
//}

// TODO: not permanent event solution, only for testing purposes
//void pollEvents(Camera2D* camera) {
//	SDL_Event event;
//	while (SDL_PollEvent(&event)) {
//		switch (event.type) {
//		case SDL_KEYDOWN:
//			handleKeyPressEvent(event.key.keysym, camera);
//		}
//	}
//}

int main(int argc, char* argv[]) {
	/*if (SDL_Init(SDL_INIT_EVENTS) == -1) {
		return -1;
	}*/

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
	Camera2D camera((float)width, (float)height, 0.1f, 100.f);
	camera.moveTo(0.f, 0.f, -10.f);
	renderer.setCamera(camera);

	SpriteRenderable spriteRenderable("base");
	spriteRenderable.setTexture("container", 0);
	spriteRenderable.setTexture("awesome", 1);
	renderer.addRenderable(spriteRenderable);

	while (!window.shouldClose()) {
		//pollEvents(&camera);
		window.processInput();
		render(window, renderer);
		window.pollInput();
	}

	destroyGlfw();

	return 0;
}