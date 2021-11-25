#pragma once

#include <map>
#include <string>

#include "renderer/renderer.h"
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
	Shader* _shader;
	std::map<uint, Texture2D*> _textures;

public:

	SpriteRenderable(const std::string& shaderName);

	static void init(SpriteRenderableVertexData* vertexData);

	void setShader(const std::string& shaderName);
	void setTexture(const std::string& textureName, const uint& textureUnit);
	void draw() override;
};
