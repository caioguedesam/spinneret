#include "renderer/renderer.h"
#include "gl_includes.h"
#include "typedefs.h"
#include "gtc/matrix_transform.hpp"

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
	SpriteRenderable::init(&_spriteRenderableVertexData);
}

void Renderer::setViewMatrix(const glm::mat4 view)
{
	_view = view;
}

void Renderer::setPerspectiveMatrix(const float& left, const float& right, const float& bottom, const float& top,
	const float& near, const float& far)
{
	_perspective = glm::ortho(left, right, bottom, top, near, far);
}

void Renderer::addRenderable(Renderable& renderable)
{
	_renderables.insert(&renderable);
	renderable.bind(this);
}

void Renderer::removeRenderable(Renderable& renderable)
{
	_renderables.erase(&renderable);
}

void Renderer::clear() const
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw() const
{
	for (auto& renderable : _renderables) {
		renderable->draw();
	}
}
