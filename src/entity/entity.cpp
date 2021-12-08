#include "entity/entity.h"
#include "components/transform_component.h"
#include <iostream>
#include <string>

Entity::Entity()
{
	addComponent(new TransformComponent());
}

Entity::~Entity()
{
	for (auto& c : _components)
	{
		delete c.second;
	}
}

void Entity::addComponent(Component* component)
{
	size_t hashcode = std::type_index(typeid(*component)).hash_code();
	_components[hashcode] = component;
	component->bindToEntity(this);
}

TransformComponent* Entity::getTransform() const
{
	return getComponent<TransformComponent>();
}

void Entity::setTag(const std::string& tag) { _tag = tag; }
std::string Entity::getTag() { return _tag; }
