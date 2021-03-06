#pragma once

#include "typedefs.h"
#include "gl_includes.h"
#include "mat4x4.hpp"

#include <string>
#include <unordered_map>

class Shader
{
private:
	mutable std::unordered_map<std::string, GLint> _uniformLocationCache;
public:
	uint shaderID;

	Shader();
	Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath);

	static void parseShaderReferenceFile(const std::string& refPath, std::string& outVertFileName, std::string& outFragFileName);
	static void parseShaderFile(const std::string& filePath, std::string& output);
	static void compileShader(GLenum shaderType, const char* shaderSource, uint& output);
	static void linkProgram(const uint& vertex, const uint& fragment, uint& output);

	void use() const;

	GLint getUniformLocation(const std::string& name) const;
	void setInt(const std::string& name, const int& value) const;
	void setFloat(const std::string& name, const float& value) const;
	void setBool(const std::string& name, const bool& value) const;
	void setMat4(const std::string& name, const glm::mat4& value) const;
};
