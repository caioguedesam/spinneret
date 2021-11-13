#pragma once
#include "typedefs.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class VertexArray {
private:
	uint _rendererID;
public:
	VertexArray();
	~VertexArray();

	void Bind();
	void Unbind();

	void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);
};
