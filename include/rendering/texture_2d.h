#pragma once

#include <string>

#include "gl_includes.h"
#include "typedefs.h"

class Texture2D
{
private:
	uint _rendererID;
	int _width, _height, _nChannels;

public:
	Texture2D();
	Texture2D(const std::string& filePath);

	void activate(const int textureUnit) const;
	void bind() const;
	void unbind() const;

	void setParameter(GLenum param, GLenum value) const;
};