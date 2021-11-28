#include "renderer/shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "logs.h"
#include "gtc/type_ptr.hpp"

Shader::Shader() : shaderID(0) {}

Shader::Shader(const std::string& vertexFilePath, const std::string& fragmentFilePath)
{
	std::string vertexSrc, fragmentSrc;
	parseShaderFile(vertexFilePath, vertexSrc);
	parseShaderFile(fragmentFilePath, fragmentSrc);
	uint vertex, fragment;
	compileShader(GL_VERTEX_SHADER, vertexSrc.c_str(), vertex);
	compileShader(GL_FRAGMENT_SHADER, fragmentSrc.c_str(), fragment);
	linkProgram(vertex, fragment, shaderID);
}

void Shader::parseShaderReferenceFile(const std::string& refPath, std::string& outVertFileName, std::string& outFragFileName)
{
	std::ifstream refFile;
	refFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		refFile.open(refPath.c_str());
		std::string line;
		while (getline(refFile, line)) {
			if (line.find("#endref") != std::string::npos) {
				break;
			}
			else if (line.find("#vert") != std::string::npos) {
				outVertFileName = line.substr(6, line.size() - 6);
			}
			else if (line.find("#frag") != std::string::npos) {
				outFragFileName = line.substr(6, line.size() - 6);
			}
		}
		refFile.close();
	}
	catch (std::ifstream::failure e) {
		logError("SHADER_REFERENCE", "failure to parse reference file at " + refPath + ":" + e.what());
	}
}

void Shader::parseShaderFile(const std::string& filePath, std::string& output)
{
	std::ifstream shaderFile;
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		shaderFile.open(filePath.c_str());
		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();
		shaderFile.close();
		output = shaderStream.str();
	}
	catch (std::ifstream::failure e) {
		logError("SHADER", "failure to parse shader file at" + filePath);
	}
}

void Shader::compileShader(GLenum shaderType, const char* shaderSource, uint& output)
{
	uint shader;
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (success) {
		output = shader;
	}
	else {
		char errorLog[512];
		glGetShaderInfoLog(shader, 512, NULL, errorLog);
		std::string msg = errorLog;
		logError("SHADER", "failure to compile shader: " + msg);
	}
}

void Shader::linkProgram(const uint& vertex, const uint& fragment, uint& output)
{
	uint program;
	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	int success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (success) {
		output = program;
	}
	else {
		char errorLog[512];
		glGetProgramInfoLog(program, 512, NULL, errorLog);
		std::string msg = errorLog;
		logError("SHADER", "failure to link shader program: " + msg);
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use() const
{
	glUseProgram(shaderID);
}

GLint Shader::getUniformLocation(const std::string& name) const
{
	// TODO: Could be optimized further by caching all uniforms on shader load
	auto it = _uniformLocationCache.find(name);
	if (it != _uniformLocationCache.end()) {
		return it->second;
	}

	GLint location = glGetUniformLocation(shaderID, name.c_str());
	_uniformLocationCache[name] = location;
	return location;
}

// TODO: calls to glGetUniformLocation can all be cached after loading the shader
void Shader::setInt(const std::string& name, const int& value) const
{
	glUniform1i(getUniformLocation(name), value);
}

void Shader::setFloat(const std::string& name, const float& value) const
{
	glUniform1f(getUniformLocation(name), value);
}

void Shader::setBool(const std::string& name, const bool& value) const
{
	glUniform1i(getUniformLocation(name), (int)value);
}

void Shader::setMat4(const std::string& name, const glm::mat4& value) const
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
}
