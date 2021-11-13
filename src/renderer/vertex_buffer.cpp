#include "renderer/vertex_buffer.h"
#include "gl_includes.h"

VertexBuffer::VertexBuffer(const void* vertexData, const uint& bufferSize)
{
	glGenBuffers(1, &_rendererID);
	glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
	glBufferData(GL_ARRAY_BUFFER, bufferSize, vertexData, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &_rendererID);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _rendererID);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
