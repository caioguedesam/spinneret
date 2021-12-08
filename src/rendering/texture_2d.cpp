#include "rendering/texture_2d.h"

#include <iostream>

#include "stb_image.h"
#include "glm.hpp"
#include "logs.h"

Texture2D::Texture2D()
	: _rendererID(0),
	_width(-1), _height(-1), _nChannels(-1) {}

Texture2D::Texture2D(const std::string& filePath)
{
	glGenTextures(1, &_rendererID);
	bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	byte* texData = stbi_load(filePath.c_str(), &_width, &_height, &_nChannels, 0);
	GLenum format;
	if (_nChannels == 3)
		format = GL_RGB;
	else if (_nChannels == 4)
		format = GL_RGBA;
	else
		logError("TEXTURE_2D", "no color format available for image with " + std::to_string(_nChannels) + " at " + filePath);

	if (texData) {
		// TODO: add support for rgba and texture alpha channels
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0,
			format, GL_UNSIGNED_BYTE, texData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		logError("TEXTURE_2D", "failed to load texture data for " + filePath);
	}
	stbi_image_free(texData);
}

void Texture2D::activate(const int textureUnit) const
{
	// Texture units only go from 0 to 15
	int offset = glm::clamp(textureUnit, 0, 15);
	glActiveTexture(GL_TEXTURE0 + offset);
}

void Texture2D::bind() const
{
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
