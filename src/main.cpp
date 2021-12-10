#include <iostream>

#include <SDL.h>

#include "main_init.h"
#include "display/display.h"
#include "rendering/rendering_system.h"
#include "loading/resource_loader.h"
#include "time/time_system.h"
#include "event/event_system.h"

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

void render(Display& display) {
	RenderingSystem::clear();
	RenderingSystem::draw();

	display.swapWindowBuffers();
}

// Temporary
Entity* getNewCamera()
{
	Entity* cameraObj = new Entity();
	cameraObj->addComponent(new Camera2DComponent((float)width, (float)height, 0.1f, 100.f));
	Camera2DComponent* camera2D = cameraObj->getComponent<Camera2DComponent>();
	camera2D->moveTo(0.f, 0.f, -10.f);
	camera2D->setAsActiveCamera();
	return cameraObj;
}

// Temporary
Entity* getNewBox()
{
	Entity* box = new Entity();
	box->addComponent(new SpriteGraphicsComponent("base"));
	SpriteGraphicsComponent* boxGraphics = box->getComponent<SpriteGraphicsComponent>();
	boxGraphics->setTexture("container", 0);
	boxGraphics->setTexture("awesome", 1);
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

void getQuitInput(SDL_Event inputEvent)
{
	SDL_Keysym key = inputEvent.key.keysym;
	if(key.sym == SDLK_ESCAPE)
		quit = true;
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
	RenderingSystem::init();
	EventSystem::init();
	EventSystem::addCallback(SDL_KEYDOWN, std::bind(&getQuitInput, std::placeholders::_1));

	Scene gameScene;

	Entity* cam = getNewCamera();
	Entity* box1 = getNewBox();
	Entity* box2 = getNewBox();
	box1->addComponent(new TestComponent());
	gameScene.addEntity(cam);
	gameScene.addEntity(box1);
	gameScene.addEntity(box2);

	while (!quit) {
		TimeSystem::updateTime();
		EventSystem::pollEvents();

		// Updating with variable dt, maybe improve later
		update(&gameScene, TimeSystem::getDeltaTime());

		render(display);
	}

	SDL_Quit();
	return 0;
}