#include "components/test_component.h"
#include "entity/entity.h"
#include "components/transform_component.h"
#include "time/time_system.h"
#include "vec3.hpp"
#include <math.h>
#include <iostream>

void TestComponent::update(double dt)
{
	const float speed = 10.f;
	const float radius = 100.f;
	TransformComponent* transform = _entity->transform();
	float x = (radius * sin((float)TimeSystem::getTime() * speed));
	float y = (radius * cos((float)TimeSystem::getTime() * speed));
	transform->setPosition(x, y, 0.0f);
}
