#pragma once

#include "component_system/entities/entity.h"

#include "vec3.hpp"
#include "mat4x4.hpp"

class TransformComponent : public Component
{
private:
	glm::mat4 _model;

	glm::vec3 _position;
	float _rotation;			// Rotation in 2D (in degrees)
	// TODO: add scale
public:
	TransformComponent(Entity* entity);

	void updateModel();

	void setPosition(glm::vec3 newPosition);
	void setPosition(float x, float y, float z);
	void setRotation(float angle);

	inline glm::mat4 getModelMatrix() const { return _model; }
	inline glm::vec3 getPosition() const { return _position; }
	inline float getRotation() const { return _rotation; }
};