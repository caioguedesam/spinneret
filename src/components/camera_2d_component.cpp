#include "components/camera_2d_component.h"
#include "components/transform_component.h"
#include "entity/entity.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/constants.hpp"

Camera2DComponent::Camera2DComponent(const float& width, const float& height, const float& near, const float& far)
	: _width(width), _height(height), _near(near), _far(far)
{
	updateProjectionMatrix();
}

void Camera2DComponent::moveTo(glm::vec3 newPosition)
{
	_entity->getTransform()->setPosition(newPosition);
}

void Camera2DComponent::moveTo(float x, float y, float z)
{
	moveTo(glm::vec3(x, y, z));
}

void Camera2DComponent::rotateTo(float newAngle)
{
	_entity->getTransform()->setRotation(newAngle);
}

glm::vec3 Camera2DComponent::getPosition() const
{
	return _entity->getTransform()->getPosition();
}

float Camera2DComponent::getRotation() const
{
	return _entity->getTransform()->getRotation();
}

float Camera2DComponent::getRotationRadians() const
{
	float rotation = getRotation();
	return rotation * (glm::pi<float>() / 180.f);
}

glm::mat4 Camera2DComponent::getViewMatrix() const
{
	return _entity->getTransform()->getModelMatrix();
}

glm::mat4 Camera2DComponent::getViewProjectionMatrix() const
{
	return _projMatrix * getViewMatrix();
}

void Camera2DComponent::updateProjectionMatrix()
{
	float halfWidth = _width / 2;
	float halfHeight = _height / 2;
	// Camera is centered on (0,0,0)
	_projMatrix = glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight, _near, _far);
}
