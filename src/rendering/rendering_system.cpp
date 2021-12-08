#include "rendering/rendering_system.h"
#include "gl_includes.h"
#include "components/sprite_graphics_component.h"

void RenderingSystem::init()
{
	RenderingSystem& instance = getInstance();
	glEnable(GL_DEPTH_TEST);
	SpriteGraphicsComponent::initQuadVertexData(&(instance._spriteQuadVertexData));
}

void RenderingSystem::setActiveCamera(Camera2DComponent* camera)
{
	getInstance()._activeCamera = camera;
}

void RenderingSystem::addDrawTarget(GraphicsComponent* target)
{
	getInstance()._drawTargets.insert(target);
}

void RenderingSystem::removeDrawTarget(GraphicsComponent* target)
{
	getInstance()._drawTargets.erase(target);
}

void RenderingSystem::clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderingSystem::draw()
{
	RenderingSystem& instance = getInstance();
	glm::mat4 viewProjectionMatrix = instance._activeCamera->getViewProjectionMatrix();
	for (auto& target : instance._drawTargets) {
		target->sendMVP(viewProjectionMatrix);
		target->draw();
	}
}
