#include "camera/camera_2d.h"
#include "gtc/matrix_transform.hpp"

Camera2D::Camera2D(const uint& width, const uint& height, const uint& near, const uint& far)
	: _width(width), _height(height), _near(near), _far(far)
{
	_position = glm::vec3(0.f, 0.f, 0.f);
	updateViewMatrix();
	updateProjectionMatrix();
}

void Camera2D::moveTo(const glm::vec3& newPosition)
{
	_position = newPosition;
	updateViewMatrix();
}

void Camera2D::updateViewMatrix()
{
	_viewMatrix = glm::lookAt(_position, _position + glm::vec3(0.f, 0.f, 1.f), glm::vec3(0.f, 1.f, 0.f));
}

void Camera2D::updateProjectionMatrix()
{
	uint halfWidth = _width / 2;
	uint halfHeight = _height / 2;
	// Camera is centered on (0,0,0)
	_projMatrix = glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight, _near, _far);
}
