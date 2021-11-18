#include "renderer/renderer.h"
#include "gl_includes.h"
#include "typedefs.h"

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
	SpriteRenderable::init(&_spriteRenderableVertexData);
}

void Renderer::addRenderable(Renderable& renderable)
{
	_renderables.insert(&renderable);
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
