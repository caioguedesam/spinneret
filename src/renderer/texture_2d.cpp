#include "renderer/texture_2d.h"

#include <iostream>

#include "stb_image.h"

Texture2D::Texture2D()
	: _rendererID(0), _textureUnit(0), 
	_width(-1), _height(-1), _nChannels(-1) {}

Texture2D::Texture2D(const std::string& filePath, const int& textureUnit)
{
	_textureUnit = textureUnit;
	glGenTextures(1, &_rendererID);
	bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	byte* texData = stbi_load(filePath.c_str(), &_width, &_height, &_nChannels, 0);
	if (texData) {
		// TODO: add support for rgba and texture alpha channels
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0,
			GL_RGB, GL_UNSIGNED_BYTE, texData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "ERROR::TEXTURE2D::Failed to load texture data for " << filePath << std::endl;
	}
	stbi_image_free(texData);
}

void Texture2D::bind() const
{
	glActiveTexture(GL_TEXTURE0 + _textureUnit);
	glBindTexture(GL_TEXTURE_2D, _rendererID);
}

void Texture2D::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::setParameter(GLenum param, GLenum value) const
{
	bind();
	glTexParameteri(GL_TEXTURE_2D, param, value);
}
