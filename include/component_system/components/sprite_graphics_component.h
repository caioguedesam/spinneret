#pragma once

#include "component_system/components/graphics_component.h"
#include "rendering/sprite_quad_vertex_data.h"
#include "rendering/texture_2d.h"

#include <map>
#include <string>
#include "typedefs.h"

class SpriteGraphicsComponent : public GraphicsComponent
{
private:
	static SpriteQuadVertexData* _quadVertexData;
	std::map<uint, Texture2D*> _textures;
public:
	SpriteGraphicsComponent(const std::string& shaderName);

	static void initQuadVertexData(SpriteQuadVertexData* vertexData);
	
	void setTexture(const std::string& textureName, const uint& textureUnit);
	void draw() override;
};