#include "component_system/components/component.h"

void Component::bindToEntity(Entity* entity)
{
	_entity = entity;
}
