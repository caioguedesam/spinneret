#include "rendering/rendering_system.h"
#include "gl_includes.h"
#include "component_system/components/sprite_graphics_component.h"

RenderingSystem::RenderingSystem()
{
	glEnable(GL_DEPTH_TEST);
	SpriteGraphicsComponent::initQuadVertexData(&_spriteQuadVertexData);
}

void RenderingSystem::setActiveCamera(Camera2DComponent* camera)
{
	_activeCamera = camera;
}

void RenderingSystem::addDrawTarget(GraphicsComponent* target)
{
	_drawTargets.insert(target);
}

void RenderingSystem::removeDrawTarget(GraphicsComponent* target)
{
	_drawTargets.erase(target);
}

void RenderingSystem::clear() const
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderingSystem::draw() const
{
	glm::mat4 viewProjectionMatrix = _activeCamera->getViewProjectionMatrix();
	for (auto& target : _drawTargets) {
		target->sendMVP(viewProjectionMatrix);
		target->draw();
	}
}
