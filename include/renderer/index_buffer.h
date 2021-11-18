#pragma once
#include "typedefs.h"

class IndexBuffer
{
private:
	uint _rendererID;
	uint _count;
public:
	IndexBuffer(const uint* indexData, const uint& bufferSize);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	inline uint getCount() const { return _count; }
};