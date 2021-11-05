#pragma once

#include "typedefs.h"
#include "gl_includes.h"

#include <string>

class Shader
{
public:
	uint shaderID;

	Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath);

	static void parseShaderFile(const std::string& filePath, std::string& output);
	static void compileShader(GLenum shaderType, const char* shaderSource, uint& output);
	static void linkProgram(const uint& vertex, const uint& fragment, uint& output);

	void use();
};
