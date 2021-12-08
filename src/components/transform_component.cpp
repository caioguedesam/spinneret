#include "components/transform_component.h"
#include "gtc/matrix_transform.hpp"

TransformComponent::TransformComponent()
	: _model(1.f), _position(0.f, 0.f, 0.f), _rotation(0.f) {}

void TransformComponent::updateModel()
{
	glm::mat4 rotation = glm::rotate(glm::mat4(1.f), _rotation, glm::vec3(0.f, 0.f, 1.f));
	glm::mat4 translation = glm::translate(glm::mat4(1.f), _position);
	_model = translation * rotation;
}

void TransformComponent::setPosition(glm::vec3 newPosition)
{
	_position = newPosition;
	updateModel();
}

void TransformComponent::setPosition(float x, float y, float z)
{
	setPosition(glm::vec3(x, y, z));
}

void TransformComponent::setRotation(float angle)
{
	_rotation = angle;
	updateModel();
}
