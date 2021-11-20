#include "renderer/renderable/sprite_renderable.h"
#include "resource_loader/resource_loader.h"

// TODO: vertices are in normalized device coordinates. Must update base shader
// to use MVP matrix and change these to object space.
float SpriteRenderableVertexData::_vertices[] = {
	// positions	  // uvs
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
	0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.5f, 0.0f, 0.0f, 1.0f
};

uint SpriteRenderableVertexData::_indices[] = {
	0, 1, 2,
	0, 2, 3
};

SpriteRenderableVertexData::SpriteRenderableVertexData()
	: vertexBuffer(SpriteRenderableVertexData::_vertices, sizeof(SpriteRenderableVertexData::_vertices)),
	indexBuffer(SpriteRenderableVertexData::_indices, sizeof(SpriteRenderableVertexData::_indices)) {}

SpriteRenderableVertexData* SpriteRenderable::_vertexData;

SpriteRenderable::SpriteRenderable(const std::string& shaderName, const std::string& textureName)
	: _shader(ResourceLoader::getShader(shaderName)),
	_texture(ResourceLoader::getTexture2D(textureName))
{}


void SpriteRenderable::init(SpriteRenderableVertexData* vertexData)
{
	_vertexData = vertexData;

	VertexBufferLayout layout;
	// position (location 0)
	layout.push<float>(3);
	// uvs (location 1)
	layout.push<float>(2);
	_vertexData->vertexArray.addBuffer(_vertexData->vertexBuffer, layout);
}

void SpriteRenderable::draw()
{
	_texture.bind();
	_shader.use();
	_vertexData->vertexArray.bind();
	_vertexData->indexBuffer.bind();

	glDrawElements(GL_TRIANGLES, _vertexData->indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}
