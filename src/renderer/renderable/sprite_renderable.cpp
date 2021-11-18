#include "renderer/renderable/sprite_renderable.h"

// TODO: vertices are in normalized device coordinates. Must update base shader
// to use MVP matrix and change these to object space.
float SpriteRenderable::_vertices[] = {
	0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
};

uint SpriteRenderable::_indices[] = {
	0, 1, 3,
	1, 2, 3
};

SpriteRenderable::SpriteRenderable(Shader& shader) 
	: _shader(shader),
	_vertexBuffer(_vertices, sizeof(_vertices)),
	_indexBuffer(_indices, sizeof(_indices))
{
	VertexBufferLayout layout;
	layout.push<float>(3);
	_vertexArray.addBuffer(_vertexBuffer, layout);
}

void SpriteRenderable::draw()
{
	_shader.use();
	_vertexArray.bind();
	_indexBuffer.bind();

	glDrawElements(GL_TRIANGLES, _indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}
