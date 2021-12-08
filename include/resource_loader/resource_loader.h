#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

#include "rendering/shader.h"
#include "rendering/texture_2d.h"
#include "logs.h"

template <class T>
class ResourceCollection
{
private:
	std::unordered_map<std::string, T> _loadedResources;
public:

	T* load(const std::string& resourcePath, const std::string& resourceKey);
	T* get(const std::string& resourceKey);
};

// Load declarations
template<class T>
T* ResourceCollection<T>::load(const std::string& resourcePath, const std::string& resourceKey)
{
	logError("RESOURCE_COLLECTION", "load not implemented for type " + typeid(T).name());
	return nullptr;
}

template<>
Shader* ResourceCollection<Shader>::load(const std::string& resourcePath, const std::string& resourceKey);
template<>
Texture2D* ResourceCollection<Texture2D>::load(const std::string& resourcePath, const std::string& resourceKey);

// Get declarations
template<class T>
T* ResourceCollection<T>::get(const std::string& resourceKey) 
{
	if (_loadedResources.count(resourceKey) == 0) {
		logError("RESOURCE_COLLECTION", "resource collection does not contain value for key " + resourceKey);
		return nullptr;
	}
	return &_loadedResources[resourceKey];
}

class ResourceLoader
{
private:
	static ResourceCollection<Shader> _shaders;
	static ResourceCollection<Texture2D> _textures;
public:

	static void init();
	static void loadInitialShaders();
	static void loadInitialTextures();

	static Shader* loadShader(const std::string& refPath, const std::string& shaderKey);
	static Shader* getShader(const std::string& shaderKey);

	static Texture2D* loadTexture2D(const std::string& texPath, const std::string& textureKey);
	static Texture2D* getTexture2D(const std::string& textureKey);
};
