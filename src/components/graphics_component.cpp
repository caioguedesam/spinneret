#include "components/graphics_component.h"
#include "entity/entity.h"
#include "components/transform_component.h"
#include "loading/resource_loader.h"
#include "vec3.hpp"
#include "gtc/matrix_transform.hpp"
#include "rendering/rendering_system.h"

GraphicsComponent::GraphicsComponent(const std::string& shaderName)
	: _model(1.f)
{
	_shader = ResourceLoader::getShader(shaderName);
	RenderingSystem::addDrawTarget(this);
}

void GraphicsComponent::setShader(const std::string& shaderName)
{
	Shader* shader = ResourceLoader::getShader(shaderName);
	if (shader == nullptr) {
		logError("RENDERABLE", "Could not load shader " + shaderName + " from resources");
		return;
	}
	_shader = shader;
}

void GraphicsComponent::sendMVP(const glm::mat4& viewProjectionMatrix)
{
	TransformComponent* transform = _entity->transform();
	glm::mat4 mvp = viewProjectionMatrix * transform->getModelMatrix();
	_shader->setMat4("u_mvp", mvp);
}
