#pragma once

#include "renderer/vertex_array.h"
#include "renderer/index_buffer.h"
#include "renderer/shader.h"

class Renderer {
public:
	void init() const;
	void clear() const;
	void draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const;
};
