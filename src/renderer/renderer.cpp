#include "renderer/renderer.h"

void Renderer::init() const
{
	glEnable(GL_DEPTH_TEST);
}

void Renderer::clear() const
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader) const
{
	shader.use();
	vertexArray.bind();
	indexBuffer.bind();

	glDrawElements(GL_TRIANGLES, indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}
