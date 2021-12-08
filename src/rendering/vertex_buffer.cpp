#include "rendering/vertex_buffer.h"
#include "gl_includes.h"

VertexBuffer::VertexBuffer(const void* vertexData, const uint& bufferSize)
{
	glGenBuffers(1, &_rendererID);
	bind();
	glBufferData(GL_ARRAY_BUFFER, bufferSize, vertexData, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &_rendererID);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
}

void VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
