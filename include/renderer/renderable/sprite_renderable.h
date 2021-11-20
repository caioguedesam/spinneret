#pragma once

#include <vector>
#include <string>

#include "renderer/renderable/renderable.h"
#include "renderer/texture_2d.h"
#include "typedefs.h"

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
	Shader& _shader;
	Texture2D& _texture;

public:

	SpriteRenderable(const std::string& shaderName, const std::string& textureName);

	static void init(SpriteRenderableVertexData* vertexData);

	void draw() override;
};
