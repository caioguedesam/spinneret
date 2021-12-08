#include <iostream>

#include <SDL.h>

#include "main_init.h"
#include "display/display.h"
#include "rendering/rendering_system.h"
#include "loading/resource_loader.h"
#include "time/time_system.h"

#include "entity/scene.h"
#include "entity/entity.h"
#include "components/transform_component.h"
#include "components/camera_2d_component.h"
#include "components/sprite_graphics_component.h"
#include "components/test_component.h"

#define TITLE "Spinneret"

int width = 800;
int height = 600;

bool quit = false;

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
		quit = true;
		break;
	}
}

// TODO: not permanent event solution, only for testing purposes
void pollEvents(Entity* camera) {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_KEYDOWN:
			handleKeyPressEvent(event.key.keysym, camera->getComponent<Camera2DComponent>());
		}
	}
}

// Temporary
Entity* getNewCamera(RenderingSystem* renderingSystem)
{
	Entity* cameraObj = new Entity();
	cameraObj->addComponent(new Camera2DComponent((float)width, (float)height, 0.1f, 100.f));
	Camera2DComponent* camera2D = cameraObj->getComponent<Camera2DComponent>();
	camera2D->moveTo(0.f, 0.f, -10.f);
	renderingSystem->setActiveCamera(camera2D);
	return cameraObj;
}

// Temporary
Entity* getNewBox(RenderingSystem* renderingSystem)
{
	Entity* box = new Entity();
	box->addComponent(new SpriteGraphicsComponent("base"));
	SpriteGraphicsComponent* boxGraphics = box->getComponent<SpriteGraphicsComponent>();
	boxGraphics->setTexture("container", 0);
	boxGraphics->setTexture("awesome", 1);
	renderingSystem->addDrawTarget(boxGraphics);
	return box;
}

void update(Scene* scene, double dt)
{
	for (auto& entity : scene->entities())
	{
		for (auto& componentEntry : entity->components())
		{
			componentEntry.second->update(dt);
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
	TimeSystem::init();
	RenderingSystem renderingSystem;

	Scene gameScene;

	Entity* cam = getNewCamera(&renderingSystem);
	Entity* box1 = getNewBox(&renderingSystem);
	Entity* box2 = getNewBox(&renderingSystem);
	box1->addComponent(new TestComponent());
	gameScene.addEntity(cam);
	gameScene.addEntity(box1);
	gameScene.addEntity(box2);

	while (!quit) {
		TimeSystem::updateTime();
		pollEvents(cam);

		update(&gameScene, TimeSystem::getDeltaTime());

		render(display, renderingSystem);
	}

	SDL_Quit();
	return 0;
}