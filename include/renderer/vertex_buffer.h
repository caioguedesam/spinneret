#pragma once
#include "typedefs.h"

class VertexBuffer
{
private:
	uint _rendererID;
public:
	VertexBuffer(const void* vertexData, const uint& bufferSize);
	~VertexBuffer();

	void Bind();
	void Unbind();
};