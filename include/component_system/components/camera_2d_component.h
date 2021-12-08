#pragma once

#include "component_system/components/component.h"

#include "vec3.hpp"
#include "mat4x4.hpp"

class Camera2DComponent : public Component
{
private:
	glm::mat4 _projMatrix;

	float _width;
	float _height;
	float _near;
	float _far;
	
	void updateProjectionMatrix();

public:
	Camera2DComponent(const float& width, const float& height, const float& near, const float& far);

	void moveTo(glm::vec3 newPosition);
	void moveTo(float x, float y, float z);
	void rotateTo(float newAngle);

	glm::vec3 getPosition() const;
	float getRotation() const;
	float getRotationRadians() const;

	glm::mat4 getViewMatrix() const;
	inline glm::mat4 getProjectionMatrix() const{ return _projMatrix; }
	glm::mat4 getViewProjectionMatrix() const;
};