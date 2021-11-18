#include "renderer/vertex_array.h"
#include "gl_includes.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &_rendererID);
	bind();
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &_rendererID);
}

void VertexArray::bind() const
{
	glBindVertexArray(_rendererID);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::addBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout)
{
	bind();
	vertexBuffer.bind();
	const std::vector<VertexBufferLayoutElement>& elements = layout.getElements();
	uint offset = 0;
	for (uint i = 0; i < elements.size(); i++) {
		const VertexBufferLayoutElement& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized,
			layout.getStride(), (const void*)offset);
		offset += element.count * VertexBufferLayoutElement::getTypeSize(element.type);
	}
}
