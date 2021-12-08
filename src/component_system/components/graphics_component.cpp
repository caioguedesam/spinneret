#include "component_system/components/graphics_component.h"
#include "component_system/entities/entity.h"
#include "component_system/components/transform_component.h"
#include "loading/resource_loader.h"
#include "vec3.hpp"
#include "gtc/matrix_transform.hpp"

GraphicsComponent::GraphicsComponent(Entity* entity, const std::string& shaderName) : Component(entity),
	_model(1.f) 
{
	_shader = ResourceLoader::getShader(shaderName);
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
	TransformComponent* transform = _entity->getTransform();
	glm::mat4 mvp = viewProjectionMatrix * transform->getModelMatrix();
	_shader->setMat4("u_mvp", mvp);
}
