#include "renderer/renderer.h"
#include "gl_includes.h"
#include "typedefs.h"
#include "gtc/matrix_transform.hpp"
#include "renderer/renderable/sprite_renderable.h"

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
	SpriteRenderable::init(&_spriteRenderableVertexData);
}

void Renderer::setCamera(Camera2D& camera)
{
	_camera = &camera;
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
	glm::mat4 viewProjectionMatrix = _camera->getViewProjectionMatrix();
	for (auto& renderable : _renderables) {
		renderable->sendMVPUniform(viewProjectionMatrix);
		renderable->draw();
	}
}
