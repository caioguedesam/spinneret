#include "components/component.h"

void Component::bindToEntity(Entity* entity)
{
	_entity = entity;
}

void Component::update(double dt) {}
