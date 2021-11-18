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

	void bind() const;
	void unbind() const;

	void addBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);
};
