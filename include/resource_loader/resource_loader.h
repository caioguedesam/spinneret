#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

#include "renderer/shader.h"

template <class T>
class ResourceCollection
{
private:
	std::unordered_map<std::string, T> _loadedResources;
public:

	T load(const std::string& resourcePath, const std::string& resourceKey);
	T get(const std::string& resourceKey);
};

// Load declarations
template<class T>
T ResourceCollection<T>::load(const std::string& resourcePath, const std::string& resourceKey)
{
	std::cout << "ERROR::RESOURCE_COLLECTION::load not implemented for type " << typeid(T).name() << std::endl;
	return NULL;
}

template<>
Shader ResourceCollection<Shader>::load(const std::string& resourcePath, const std::string& resourceKey);

// Get declarations
template<class T>
inline T ResourceCollection<T>::get(const std::string& resourceKey) { return _loadedResources[resourceKey]; }
