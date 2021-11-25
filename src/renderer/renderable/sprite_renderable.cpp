#include "renderer/renderable/sprite_renderable.h"
#include "resource_loader/resource_loader.h"
#include "logs.h"

SpriteRenderableVertexData* SpriteRenderable::_vertexData;

SpriteRenderable::SpriteRenderable(const std::string& shaderName)
{
	setShader(shaderName);
}


void SpriteRenderable::init(SpriteRenderableVertexData* vertexData)
{
	_vertexData = vertexData;

	VertexBufferLayout layout;
	// position (location 0)
	layout.push<float>(3);
	// uvs (location 1)
	layout.push<float>(2);
	_vertexData->vertexArray.addBuffer(_vertexData->vertexBuffer, layout);
}

void SpriteRenderable::setTexture(const std::string& textureName, const uint& textureUnit)
{
	Texture2D* texture = ResourceLoader::getTexture2D(textureName);
	if (texture == nullptr) {
		logError("SPRITE_RENDERABLE", "Could not load texture " + textureName + " from resources");
		return;
	}
	_textures.insert(std::pair<uint, Texture2D*>(textureUnit, ResourceLoader::getTexture2D(textureName)));
}

void SpriteRenderable::draw()
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
	_vertexData->vertexArray.bind();
	_vertexData->indexBuffer.bind();

	glDrawElements(GL_TRIANGLES, _vertexData->indexBuffer.getCount(), GL_UNSIGNED_INT, 0);
}
