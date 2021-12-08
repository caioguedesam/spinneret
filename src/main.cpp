#include <iostream>

#include <SDL.h>

#include "main_init.h"
#include "display/display.h"
#include "rendering/rendering_system.h"
#include "loading/resource_loader.h"

#include "component_system/entities/entity.h"
#include "component_system/components/transform_component.h"
#include "component_system/components/camera_2d_component.h"
#include "component_system/components/sprite_graphics_component.h"

#define TITLE "Spinneret"

int width = 800;
int height = 600;

bool isRunning = true;

void render(Display& display, RenderingSystem& renderingSystem) {
	renderingSystem.clear();
	renderingSystem.draw();

	display.swapWindowBuffers();
}

void handleKeyPressEvent(SDL_Keysym& key, Camera2DComponent* camera) {
	glm::vec3 cameraPos = camera->getPosition();
	float cameraAngle = camera->getRotation();
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
void pollEvents(Camera2DComponent* camera) {
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
	RenderingSystem renderingSystem;

	Entity cameraObj;
	cameraObj.addComponent(std::type_index(typeid(Camera2DComponent)),
		new Camera2DComponent(&cameraObj, (float)width, (float)height, 0.1f, 100.f));
	Camera2DComponent* camera2D = cameraObj.getComponent<Camera2DComponent>();
	camera2D->moveTo(0.f, 0.f, -10.f);
	renderingSystem.setActiveCamera(camera2D);

	Entity box;
	box.addComponent(std::type_index(typeid(SpriteGraphicsComponent)), new SpriteGraphicsComponent(&box, "base"));
	SpriteGraphicsComponent* boxGraphics = box.getComponent<SpriteGraphicsComponent>();
	boxGraphics->setTexture("container", 0);
	boxGraphics->setTexture("awesome", 1);
	renderingSystem.addDrawTarget(boxGraphics);

	Entity box2;
	box2.addComponent(std::type_index(typeid(SpriteGraphicsComponent)), new SpriteGraphicsComponent(&box2, "base"));
	SpriteGraphicsComponent* boxGraphics2 = box2.getComponent<SpriteGraphicsComponent>();
	boxGraphics2->setTexture("container", 0);
	boxGraphics2->setTexture("awesome", 1);
	renderingSystem.addDrawTarget(boxGraphics2);

	TransformComponent* boxTransform = box.getTransform();
	TransformComponent* box2Transform = box2.getTransform();
	while (isRunning) {
		boxTransform->setPosition(boxTransform->getPosition().x + 0.05f, 0.f, 0.f);
		box2Transform->setPosition(box2Transform->getPosition().x + 0.025f, box2Transform->getPosition().y + 0.01f, 0.f);
		pollEvents(camera2D);
		render(display, renderingSystem);
	}

	SDL_Quit();
	return 0;
}