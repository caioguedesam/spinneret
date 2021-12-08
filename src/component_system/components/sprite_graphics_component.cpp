#include "component_system/components/sprite_graphics_component.h"
#include "loading/resource_loader.h"

SpriteQuadVertexData* SpriteGraphicsComponent::_quadVertexData;

SpriteGraphicsComponent::SpriteGraphicsComponent(Entity* entity, const std::string& shaderName)
	: GraphicsComponent(entity, shaderName) {}

void SpriteGraphicsComponent::initQuadVertexData(SpriteQuadVertexData* vertexData)
{
	_quadVertexData = vertexData;

	VertexBufferLayout layout;
	// position (location 0)
	layout.push<float>(3);
	// uvs (location 1)
	layout.push<float>(2);
	_quadVertexData->vertexArray.addBuffer(_quadVertexData->vertexBuffer, layout);
}

void SpriteGraphicsComponent::setTexture(const std::string& textureName, const uint& textureUnit)
{
	Texture2D* texture = ResourceLoader::getTexture2D(textureName);
	if (texture == nullptr) {
		logError("SPRITE_RENDERABLE", "Could not load texture " + textureName + " from resources");
		return;
	}
	_textures.insert(std::pair<uint, Texture2D*>(textureUnit, ResourceLoader::getTexture2D(textureName)));
}

void SpriteGraphicsComponent::draw()
{
	int i = 0;
	const std::string texName = "tex_";
	for (auto const& entry : _textures) {
		int texUnit = entry.first;
		Texture2D* texture = entry.second;
		texture->activate(texUnit);
		texture->bind();
		_shader->setInt(texName + std::to_string(i), texUnit);
		i++;
	}
	_shader->use();
	_quadVertexData->vertexArray.bind();
	_quadVertexData->indexBuffer.bind();

	glDrawElements(GL_TRIANGLES, _quadVertexData->indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}
