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
	std::unordered_map<size_t, Component*> _components;
public:
	Entity();
	~Entity();

	void addComponent(Component* component);
	template <typename T>
	T* getComponent() const
	{
		size_t hashcode = std::type_index(typeid(T)).hash_code();
		auto it = _components.find(hashcode);
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
