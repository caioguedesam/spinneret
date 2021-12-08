#pragma once

#include <string>
#include <unordered_map>
#include <typeindex>

#include "component_system/components/component.h"

class TransformComponent;

class Entity
{
private:
	std::string _tag;
	std::unordered_map<std::type_index, Component*> _components;
public:
	Entity();
	~Entity();

	void addComponent(std::type_index type, Component* component);
	template <typename T>
	T* getComponent() const
	{
		auto it = _components.find(std::type_index(typeid(T)));
		if (it != _components.end())
		{
			return dynamic_cast<T*>(it->second);
		}
		return nullptr;
	}

	TransformComponent* getTransform() const;

	void setTag(const std::string& tag);
	std::string getTag();
};
