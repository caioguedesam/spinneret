#pragma once

#include "components/component.h"
#include "rendering/shader.h"

#include "mat4x4.hpp"
#include <string>

class GraphicsComponent : public Component
{
private:
	glm::mat4 _model;
protected:
	Shader* _shader;
public:
	GraphicsComponent(const std::string& shaderName);

	void setShader(const std::string& shaderName);
	void sendMVP(const glm::mat4& viewProjectionMatrix);

	virtual void draw() = 0;
};