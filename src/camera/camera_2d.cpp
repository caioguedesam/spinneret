#include "camera/camera_2d.h"
#include "gtc/matrix_transform.hpp"
#include "gtx/string_cast.hpp"
#include <iostream>

Camera2D::Camera2D(const float& width, const float& height, const float& near, const float& far)
	: _width(width), _height(height), _near(near), _far(far),
	_position(0.f, 0.f, 0.f), _angleDegrees(0.f),
	_viewMatrix(1.f)
{
	updateViewMatrix();
	updateProjectionMatrix();
}

void Camera2D::moveTo(const glm::vec3& newPosition)
{
	_position = newPosition;
	updateViewMatrix();
}

void Camera2D::moveTo(const float& x, const float& y, const float& z)
{
	moveTo(glm::vec3(x, y, z));
}

void Camera2D::rotateTo(const float& angle)
{
	_angleDegrees = angle;
	updateViewMatrix();
}

void Camera2D::updateViewMatrix()
{
	glm::mat4 rotation = glm::rotate(glm::mat4(1.f), getAngleInRad(), glm::vec3(0.f, 0.f, 1.f));
	glm::mat4 translation = glm::translate(glm::mat4(1.f), _position);
	_viewMatrix = translation * rotation;
}

void Camera2D::updateProjectionMatrix()
{
	float halfWidth = _width / 2;
	float halfHeight = _height / 2;
	// Camera is centered on (0,0,0)
	_projMatrix = glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight, _near, _far);
}
