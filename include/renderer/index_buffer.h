#pragma once
#include "typedefs.h"

class IndexBuffer
{
private:
	uint _rendererID;
public:
	IndexBuffer(const uint* indexData, const uint& bufferSize);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
};