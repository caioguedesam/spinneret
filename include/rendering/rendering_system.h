#pragma once

#include <set>

#include "camera/camera_2d.h"
#include "rendering/sprite_quad_vertex_data.h"
#include "component_system/components/graphics_component.h"

class RenderingSystem {
private:
	std::set<GraphicsComponent*> _drawTargets;

	Camera2D* _camera;

	SpriteQuadVertexData _spriteQuadVertexData;
public:
	
	RenderingSystem();

	void setCamera(Camera2D& camera);
	void addDrawTarget(GraphicsComponent* target);
	void removeDrawTarget(GraphicsComponent* target);

	void clear() const;
	void draw() const;
};
