#include "renderer/vertex_array.h"
#include "gl_includes.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &_rendererID);
	Bind();
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &_rendererID);
}

void VertexArray::Bind()
{
	glBindVertexArray(_rendererID);
}

void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout)
{
	Bind();
	vertexBuffer.Bind();
	const std::vector<VertexBufferLayoutElement>& elements = layout.GetElements();
	uint offset = 0;
	for (uint i = 0; i < elements.size(); i++) {
		const VertexBufferLayoutElement& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, element.count, element.type, element.normalized,
			layout.GetStride(), (const void*)offset);
		offset += element.count * VertexBufferLayoutElement::GetTypeSize(element.type);
	}
}
