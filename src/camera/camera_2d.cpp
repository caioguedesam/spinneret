#include "camera/camera_2d.h"
#include "gtc/matrix_transform.hpp"

Camera2D::Camera2D(const float& width, const float& height, const float& near, const float& far)
	: _width(width), _height(height), _near(near), _far(far),
	_position(0.f, 0.f, 0.f), _viewMatrix(1.f)
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

void Camera2D::updateViewMatrix()
{
	// TODO: add rotation transform
	_viewMatrix = glm::translate(_viewMatrix, _position);
}

void Camera2D::updateProjectionMatrix()
{
	float halfWidth = _width / 2;
	float halfHeight = _height / 2;
	// Camera is centered on (0,0,0)
	_projMatrix = glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight, _near, _far);
}
