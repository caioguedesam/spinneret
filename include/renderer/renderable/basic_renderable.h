#pragma once

#include "renderer/renderable/renderable.h"

class BasicRenderable : public Renderable
{
private:
	const VertexArray& _vertexArray;
	const IndexBuffer& _indexBuffer;
	const Shader& _shader;
public:

	BasicRenderable(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const Shader& shader);

	void draw() override;
};