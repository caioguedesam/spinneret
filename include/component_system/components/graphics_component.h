#pragma once

#include "component_system/entities/entity.h"
#include "component_system/components/component.h"
#include "renderer/shader.h"

#include "mat4x4.hpp"
#include <string>

class GraphicsComponent : public Component
{
private:
	glm::mat4 _model;
protected:
	Shader* _shader;
public:
	// TODO: Subscribe GraphicsComponent to RenderingSystem
	GraphicsComponent(Entity* entity, const std::string& shaderName);

	void setShader(const std::string& shaderName);
	void sendMVP(const glm::mat4& viewProjectionMatrix);

	virtual void draw() = 0;
};