#include "resource_loader/resource_loader.h"

template<>
Shader ResourceCollection<Shader>::load(const std::string& resourcePath, const std::string& resourceKey) {
	if (_loadedResources.count(resourceKey)) {
		return get(resourceKey);
	}

	std::string vertName, fragName;
	Shader::parseShaderReferenceFile("resources/shaders/refs/" + resourcePath, vertName, fragName);
	std::string vertPath = "resources/shaders/glsl/" + vertName;
	std::string fragPath = "resources/shaders/glsl/" + fragName;

	Shader shader(vertPath, fragPath);
	_loadedResources.insert({ resourceKey, shader });
	return shader;
}