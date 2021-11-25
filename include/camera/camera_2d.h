#pragma once

#include "vec3.hpp"
#include "mat4x4.hpp"
#include "typedefs.h"

class Camera2D
{
private:
	glm::vec3 _position;
	glm::mat4 _viewMatrix;
	glm::mat4 _projMatrix;

	uint _width;
	uint _height;
	uint _near;
	uint _far;
	
	void updateViewMatrix();
	void updateProjectionMatrix();

public:
	Camera2D(const uint& width, const uint& height, const uint& near, const uint& far);

	void moveTo(const glm::vec3& newPosition);
};