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

	glm::mat4 _model;
public:

	void bind(Renderer* renderer);
	glm::mat4 getMVP() const;
	virtual void draw() = 0;
};
