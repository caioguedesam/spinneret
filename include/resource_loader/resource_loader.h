#pragma once

#include <string>
#include <unordered_map>
#include <iostream>

#include "renderer/shader.h"
#include "renderer/texture_2d.h"

template <class T>
class ResourceCollection
{
private:
	std::unordered_map<std::string, T> _loadedResources;
public:

	T& load(const std::string& resourcePath, const std::string& resourceKey);
	T& get(const std::string& resourceKey);
};

// Load declarations
template<class T>
T& ResourceCollection<T>::load(const std::string& resourcePath, const std::string& resourceKey)
{
	std::cout << "ERROR::RESOURCE_COLLECTION::load not implemented for type " << typeid(T).name() << std::endl;
	return NULL;
}

template<>
Shader& ResourceCollection<Shader>::load(const std::string& resourcePath, const std::string& resourceKey);
template<>
Texture2D& ResourceCollection<Texture2D>::load(const std::string& resourcePath, const std::string& resourceKey);

// Get declarations
template<class T>
inline T& ResourceCollection<T>::get(const std::string& resourceKey) { return _loadedResources[resourceKey]; }

class ResourceLoader
{
private:
	static ResourceCollection<Shader> _shaders;
	static ResourceCollection<Texture2D> _textures;
public:

	static void init();
	static void loadInitialShaders();
	static void loadInitialTextures();

	static Shader& loadShader(const std::string& refPath, const std::string& shaderKey);
	static Shader& getShader(const std::string& shaderKey);

	static Texture2D& loadTexture2D(const std::string& texPath, const std::string& textureKey);
	static Texture2D& getTexture2D(const std::string& textureKey);
};
