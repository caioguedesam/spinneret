#pragma once

#include "gl_includes.h"
#include "typedefs.h"
#include <vector>

struct VertexBufferLayoutElement {
	uint type;
	uint count;
	byte normalized;

	static uint getTypeSize(const uint& type) {
		switch (type) {
			case GL_FLOAT:	return sizeof(GLfloat);
			case GL_UNSIGNED_INT: return sizeof(GLuint);
			case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
		}
		return 0;
	}
};

class VertexBufferLayout {
private:
	std::vector<VertexBufferLayoutElement> _elements;
	uint _stride;
public:
	VertexBufferLayout() : _stride(0) {}

	template<typename T>
	void push(const uint& count) {}

	template<> void push<float>(const uint& count) {
		VertexBufferLayoutElement element = {
			GL_FLOAT,
			count,
			GL_FALSE
		};
		_elements.push_back(element);
		_stride += count * VertexBufferLayoutElement::getTypeSize(GL_FLOAT);
	}
	template<> void push<uint>(const uint& count) {
		VertexBufferLayoutElement element = {
			GL_UNSIGNED_INT,
			count,
			GL_FALSE
		};
		_elements.push_back(element);
		_stride += count * VertexBufferLayoutElement::getTypeSize(GL_UNSIGNED_INT);
	}
	template<> void push<byte>(const uint& count) {
		VertexBufferLayoutElement element = {
			GL_UNSIGNED_BYTE,
			count,
			GL_TRUE
		};
		_elements.push_back(element);
		_stride += count * VertexBufferLayoutElement::getTypeSize(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferLayoutElement>& getElements() const { return _elements; }
	inline uint getStride() const { return _stride; }
};
