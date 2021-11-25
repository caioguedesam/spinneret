#include "renderer/renderable/sprite_renderable_vertex_data.h"

// TODO: vertices are in normalized device coordinates. Must update base shader
// to use MVP matrix and change these to object space.
float SpriteRenderableVertexData::_vertices[] = {
	// positions	  // uvs
	0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	100.0f, 0.0f, 0.0f, 1.0f, 0.0f,
	100.0f, 100.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 100.0f, 0.0f, 0.0f, 1.0f
};

uint SpriteRenderableVertexData::_indices[] = {
	0, 1, 2,
	0, 2, 3
};

SpriteRenderableVertexData::SpriteRenderableVertexData()
	: vertexBuffer(SpriteRenderableVertexData::_vertices, sizeof(SpriteRenderableVertexData::_vertices)),
	indexBuffer(SpriteRenderableVertexData::_indices, sizeof(SpriteRenderableVertexData::_indices)) {}