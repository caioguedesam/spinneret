#include "rendering/sprite_quad_vertex_data.h"

float SpriteQuadVertexData::_vertices[] = {
	// positions			// uvs
	0.0f, 0.0f, 0.0f,		0.0f, 0.0f,
	100.0f, 0.0f, 0.0f,		1.0f, 0.0f,
	100.0f, 100.0f, 0.0f,	1.0f, 1.0f,
	0.0f, 100.0f, 0.0f,		0.0f, 1.0f
};

uint SpriteQuadVertexData::_indices[] = {
	0, 1, 2,
	0, 2, 3
};

SpriteQuadVertexData::SpriteQuadVertexData()
	: vertexBuffer(SpriteQuadVertexData::_vertices, sizeof(SpriteQuadVertexData::_vertices)),
	indexBuffer(SpriteQuadVertexData::_indices, sizeof(SpriteQuadVertexData::_indices)) {}