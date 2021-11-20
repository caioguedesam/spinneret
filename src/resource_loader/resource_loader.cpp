#include "resource_loader/resource_loader.h"

template<>
Shader& ResourceCollection<Shader>::load(const std::string& resourcePath, const std::string& resourceKey) 
{
	if (_loadedResources.count(resourceKey)) {
		return get(resourceKey);
	}

	std::string vertName, fragName;
	Shader::parseShaderReferenceFile("resources/shaders/refs/" + resourcePath, vertName, fragName);
	std::string vertPath = "resources/shaders/glsl/" + vertName;
	std::string fragPath = "resources/shaders/glsl/" + fragName;

	Shader shader(vertPath, fragPath);
	_loadedResources.insert({ resourceKey, shader });
	return get(resourceKey);
}

template<>
Texture2D& ResourceCollection<Texture2D>::load(const std::string& resourcePath, const std::string& resourceKey) 
{
	if (_loadedResources.count(resourceKey)) {
		return get(resourceKey);
	}

	std::string tex2dPath = "resources/textures/" + resourcePath;
	Texture2D texture(tex2dPath);
	// TODO: load texture options
	_loadedResources.insert({ resourceKey, texture });
	return get(resourceKey);
}

ResourceCollection<Shader> ResourceLoader::_shaders;
ResourceCollection<Texture2D> ResourceLoader::_textures;

void ResourceLoader::init()
{
	loadInitialTextures();
	loadInitialShaders();
}

void ResourceLoader::loadInitialShaders()
{
	// TODO: make some sort of file to read dynamically ref paths to load instead of manual
	loadShader("base.glslref", "base");
}

void ResourceLoader::loadInitialTextures()
{
	// TODO: make some sort of file to read dynamically ref paths to load instead of manual
	loadTexture2D("container.jpg", "container");
	loadTexture2D("awesomeface.png", "awesome");
}

Shader& ResourceLoader::loadShader(const std::string& refPath, const std::string& shaderKey)
{
	return _shaders.load(refPath, shaderKey);
}

Shader& ResourceLoader::getShader(const std::string& shaderKey)
{
	return _shaders.get(shaderKey);
}

Texture2D& ResourceLoader::loadTexture2D(const std::string& texPath, const std::string& textureKey)
{
	return _textures.load(texPath, textureKey);
}

Texture2D& ResourceLoader::getTexture2D(const std::string& textureKey)
{
	return _textures.get(textureKey);
}
