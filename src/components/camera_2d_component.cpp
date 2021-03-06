#include "components/camera_2d_component.h"
#include "components/transform_component.h"
#include "entity/entity.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/constants.hpp"
#include "rendering/rendering_system.h"
#include "event/event_system.h"

Camera2DComponent::Camera2DComponent(const float& width, const float& height, const float& near, const float& far)
	: _width(width), _height(height), _near(near), _far(far)
{
	updateProjectionMatrix();
	EventSystem::addCallback(SDL_KEYDOWN, this, &Camera2DComponent::processInput);
}

void Camera2DComponent::setAsActiveCamera()
{
	RenderingSystem::setActiveCamera(this);
}

void Camera2DComponent::moveTo(glm::vec3 newPosition)
{
	_entity->transform()->setPosition(newPosition);
}

void Camera2DComponent::moveTo(float x, float y, float z)
{
	moveTo(glm::vec3(x, y, z));
}

void Camera2DComponent::rotateTo(float newAngle)
{
	_entity->transform()->setRotation(newAngle);
}

glm::vec3 Camera2DComponent::getPosition() const
{
	return _entity->transform()->getPosition();
}

float Camera2DComponent::getRotation() const
{
	return _entity->transform()->getRotation();
}

float Camera2DComponent::getRotationRadians() const
{
	float rotation = getRotation();
	return rotation * (glm::pi<float>() / 180.f);
}

glm::mat4 Camera2DComponent::getViewMatrix() const
{
	return _entity->transform()->getModelMatrix();
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

void Camera2DComponent::processInput(SDL_Event inputEvent)
{
	glm::vec3 cameraPos = getPosition();
	float cameraAngle = getRotation();
	const float cameraSpeed = 2.25f;
	SDL_Keysym key = inputEvent.key.keysym;
	switch (key.sym) {
		// Camera movement
		case SDLK_UP:
			moveTo(cameraPos + cameraSpeed * glm::vec3(0.f, 1.f, 0.f));
			break;
		case SDLK_DOWN:
			moveTo(cameraPos - cameraSpeed * glm::vec3(0.f, 1.f, 0.f));
			break;
		case SDLK_LEFT:
			moveTo(cameraPos - cameraSpeed * glm::vec3(1.f, 0.f, 0.f));
			break;
		case SDLK_RIGHT:
			moveTo(cameraPos + cameraSpeed * glm::vec3(1.f, 0.f, 0.f));
			break;
			// Camera rotation
		case SDLK_a:
			rotateTo(cameraAngle - 0.5f);
			break;
		case SDLK_d:
			rotateTo(cameraAngle + 0.5f);
			break;
	}
}
