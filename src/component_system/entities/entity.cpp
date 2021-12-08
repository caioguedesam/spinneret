#include "component_system/entities/entity.h"
#include "component_system/components/transform_component.h"

Entity::Entity()
{
	addComponent(std::type_index(typeid(TransformComponent)), new TransformComponent(this));
}

Entity::~Entity()
{
	for (auto& c : _components)
	{
		delete c.second;
	}
}

void Entity::addComponent(std::type_index type, Component* component)
{
	_components[type] = component;
}

void Entity::setTag(const std::string& tag) { _tag = tag; }
std::string Entity::getTag() { return _tag; }
