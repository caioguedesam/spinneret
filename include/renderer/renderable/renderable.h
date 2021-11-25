#pragma once

#include "renderer/vertex_array.h"
#include "renderer/index_buffer.h"
#include "renderer/shader.h"
#include "mat4x4.hpp"

class Renderer;

class Renderable
{
private:
	Renderer* _renderer;
protected:
	Shader* _shader;

	glm::mat4 _model;
public:

	void bind(Renderer* renderer);

	void setShader(const std::string& shaderName);
	void sendMVPUniform(const glm::mat4& view_projection_matrix);

	virtual void draw() = 0;
};
