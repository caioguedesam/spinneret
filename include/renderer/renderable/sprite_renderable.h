#pragma once

#include <vector>

#include "renderer/renderable/renderable.h"
#include "typedefs.h"
#include <memory>

struct SpriteRenderableVertexData
{
	static float _vertices[];
	static uint _indices[];

	VertexArray vertexArray;
	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;

	SpriteRenderableVertexData();

};

class SpriteRenderable : public Renderable
{
private:
	static SpriteRenderableVertexData* _vertexData;
	
	// TODO: add support for setting mvp matrix (with caching maybe)
	// TOOD: add texture support
	Shader& _shader;

public:

	SpriteRenderable(Shader& shader);

	static void init(SpriteRenderableVertexData* vertexData);

	void draw() override;
};
