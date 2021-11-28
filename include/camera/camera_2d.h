#pragma once

#include "vec3.hpp"
#include "mat4x4.hpp"
#include "gtc/constants.hpp"
#include "typedefs.h"

class Camera2D
{
private:
	glm::vec3 _position;
	float _angleDegrees;
	glm::mat4 _viewMatrix;
	glm::mat4 _projMatrix;

	float _width;
	float _height;
	float _near;
	float _far;
	
	void updateViewMatrix();
	void updateProjectionMatrix();

public:
	Camera2D(const float& width, const float& height, const float& near, const float& far);

	void moveTo(const glm::vec3& newPosition);
	void moveTo(const float& x, const float& y, const float& z);
	void rotateTo(const float& angle);

	inline glm::vec3 getPosition() const { return _position; }
	inline float getAngle() const { return _angleDegrees; }
	inline float getAngleInRad() const { return _angleDegrees * (glm::pi<float>() / 180.f); }
	inline glm::mat4 getViewMatrix() const { return _viewMatrix; }
	inline glm::mat4 getProjectionMatrix() const { return _projMatrix; }
	inline glm::mat4 getViewProjectionMatrix() const { return _projMatrix * _viewMatrix; }
};