#pragma once

#include "renderer/vertex_array.h"
#include "renderer/index_buffer.h"
#include "renderer/shader.h"

class Renderable
{
public:
	virtual void draw() = 0;
};
