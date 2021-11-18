#include "resource_loader/resource_loader.h"

template<>
Shader& ResourceCollection<Shader>::load(const std::string& resourcePath, const std::string& resourceKey) {
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

ResourceCollection<Shader> ResourceLoader::_shaders;

void ResourceLoader::init()
{
	loadInitialShaders();
}

void ResourceLoader::loadInitialShaders()
{
	// TODO: make some sort of file to read dynamically ref paths to load instead of manual
	loadShader("base.glslref", "base");
}

void ResourceLoader::loadShader(const std::string& refPath, const std::string& shaderKey)
{
	_shaders.load(refPath, shaderKey);
}

Shader& ResourceLoader::getShader(const std::string& shaderKey)
{
	return _shaders.get(shaderKey);
}
