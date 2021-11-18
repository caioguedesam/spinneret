#pragma once

#include <vector>

#include "renderer/renderable/renderable.h"
#include "typedefs.h"
#include <string>

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

	//SpriteRenderable(Shader& shader);
	SpriteRenderable(const std::string& shaderName);

	static void init(SpriteRenderableVertexData* vertexData);

	void draw() override;
};
