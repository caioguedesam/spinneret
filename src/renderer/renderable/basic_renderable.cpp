#include "renderer/renderable/basic_renderable.h"

BasicRenderable::BasicRenderable(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader)
	: _vertexArray(vertexArray), _indexBuffer(indexBuffer), _shader(shader) {}

void BasicRenderable::draw()
{
	_shader.use();
	_vertexArray.bind();
	_indexBuffer.bind();

	glDrawElements(GL_TRIANGLES, _indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}
