#pragma once

#include <map>
#include <string>

#include "renderer/renderer.h"
#include "renderer/renderable/renderable.h"
#include "renderer/renderable/sprite_renderable_vertex_data.h"
#include "renderer/texture_2d.h"
#include "typedefs.h"

class SpriteRenderable : public Renderable
{
private:
	static SpriteRenderableVertexData* _vertexData;
	std::map<uint, Texture2D*> _textures;

public:

	SpriteRenderable(const std::string& shaderName);

	static void init(SpriteRenderableVertexData* vertexData);

	void setTexture(const std::string& textureName, const uint& textureUnit);
	void draw() override;
};
