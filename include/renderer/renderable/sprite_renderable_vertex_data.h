#pragma once

#include "typedefs.h"
#include "renderer/vertex_array.h"
#include "renderer/vertex_buffer.h"
#include "renderer/index_buffer.h"

struct SpriteRenderableVertexData
{
	static float _vertices[];
	static uint _indices[];

	VertexArray vertexArray;
	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;

	SpriteRenderableVertexData();
};