#include "renderer/renderable/sprite_renderable.h"

// TODO: vertices are in normalized device coordinates. Must update base shader
// to use MVP matrix and change these to object space.
// TODO: this data is not from a square, it's a rectangle
float SpriteRenderableVertexData::_vertices[] = {
	0.5f,  0.5f, 0.0f,  // top right
	 0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
};

uint SpriteRenderableVertexData::_indices[] = {
	0, 1, 3,
	1, 2, 3
};

SpriteRenderableVertexData::SpriteRenderableVertexData()
	: vertexBuffer(SpriteRenderableVertexData::_vertices, sizeof(SpriteRenderableVertexData::_vertices)),
	indexBuffer(SpriteRenderableVertexData::_indices, sizeof(SpriteRenderableVertexData::_indices)) {}

SpriteRenderableVertexData* SpriteRenderable::_vertexData;

SpriteRenderable::SpriteRenderable(Shader& shader)
	: _shader(shader) {}

void SpriteRenderable::init(SpriteRenderableVertexData* vertexData)
{
	_vertexData = vertexData;

	VertexBufferLayout layout;
	layout.push<float>(3);
	_vertexData->vertexArray.addBuffer(_vertexData->vertexBuffer, layout);
}

void SpriteRenderable::draw()
{
	_shader.use();
	_vertexData->vertexArray.bind();
	_vertexData->indexBuffer.bind();

	glDrawElements(GL_TRIANGLES, _vertexData->indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}
