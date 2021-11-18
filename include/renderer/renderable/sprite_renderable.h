#pragma once

#include <vector>

#include "renderer/renderable/renderable.h"
#include "typedefs.h"

class SpriteRenderable : public Renderable
{
private:
	static float _vertices[];
	static uint _indices[];

	static bool _initialized;

	// TODO: figure out way to use only one VertexArray (and buffers) for all SpriteRenderables
	VertexArray _vertexArray;
	VertexBuffer _vertexBuffer;
	IndexBuffer _indexBuffer;
	
	// TODO: add support for setting mvp matrix (with caching maybe)
	// TOOD: add texture support
	Shader& _shader;

public:

	SpriteRenderable(Shader& shader);

	void draw() override;
};
