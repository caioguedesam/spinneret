#include "rendering/index_buffer.h"

#include "gl_includes.h"

IndexBuffer::IndexBuffer(const uint* indexData, const uint& bufferSize) : _count(bufferSize)
{
	glGenBuffers(1, &_rendererID);
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, indexData, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &_rendererID);
}

void IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererID);
}

void IndexBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
