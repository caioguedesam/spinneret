#include "components/test_component.h"
#include "entity/entity.h"
#include "components/transform_component.h"
#include "time/time_system.h"
#include "event/event_system.h"
#include "event/event_codes.h"
#include "vec3.hpp"
#include <math.h>
#include <iostream>

TestComponent::TestComponent()
	: _respondCount(0)
{
	EventSystem::addCallback(SDL_KEYDOWN, this, &TestComponent::raiseTestEvent);
	EventSystem::addCallback(EventSystem::getGameEventType(), this, &TestComponent::respondToTestEvent);
}

void TestComponent::update(double dt)
{
	const float speed = 10.f;
	const float radius = 100.f;
	TransformComponent* transform = _entity->transform();
	float x = (radius * sin((float)TimeSystem::getTime() * speed));
	float y = (radius * cos((float)TimeSystem::getTime() * speed));
	transform->setPosition(x, y, 0.0f);
}

void TestComponent::raiseTestEvent(SDL_Event event)
{
	SDL_Keysym key = event.key.keysym;
	if (key.sym == SDLK_p)
	{
		std::cout << "Raising test event..." << std::endl;
		EventSystem::raiseEvent(EVENT_TEST, (void*)"Hello!");
	}
}

void TestComponent::respondToTestEvent(SDL_Event event)
{
	if (event.user.code != EVENT_TEST) return;
	_respondCount++;
	std::cout << "Responded to event " << _respondCount << " times. Custom data: " << static_cast<const char*>(event.user.data1) << std::endl;
}
