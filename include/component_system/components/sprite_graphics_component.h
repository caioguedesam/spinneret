#pragma once

#include "component_system/components/graphics_component.h"
#include "renderer/renderable/sprite_renderable_vertex_data.h"
#include "renderer/texture_2d.h"

#include <map>
#include <string>
#include "typedefs.h"

class SpriteGraphicsComponent : public GraphicsComponent
{
private:
	static SpriteRenderableVertexData* _quadVertexData;
	std::map<uint, Texture2D*> _textures;
public:
	SpriteGraphicsComponent(Entity* entity, const std::string& textureName, const std::string& shaderName);

	static void initQuadVertexData(SpriteRenderableVertexData* vertexData);
	
	void setTexture(const std::string& textureName, const uint& textureUnit);
	void draw() override;
};