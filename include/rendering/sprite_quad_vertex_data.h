#pragma once

#include "typedefs.h"
#include "rendering/vertex_array.h"
#include "rendering/vertex_buffer.h"
#include "rendering/index_buffer.h"

struct SpriteQuadVertexData
{
	static float _vertices[];
	static uint _indices[];

	VertexArray vertexArray;
	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;

	SpriteQuadVertexData();
};
