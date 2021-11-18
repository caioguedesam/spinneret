#pragma once

#include <string>

#include "typedefs.h"

class Texture2D
{
private:
	uint _rendererID;
	int _width, _height, _nChannels;

public:
	Texture2D();
	Texture2D(const std::string& filePath);

	void bind() const;
	void unbind() const;
};
