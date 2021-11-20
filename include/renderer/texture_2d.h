#pragma once

#include <string>

#include "typedefs.h"

class Texture2D
{
private:
	uint _rendererID;
	uint _textureUnit;
	int _width, _height, _nChannels;

public:
	Texture2D();
	Texture2D(const std::string& filePath, const int& textureUnit = 0);

	void bind() const;
	void unbind() const;
};
