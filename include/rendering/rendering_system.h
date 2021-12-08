#pragma once

#include <set>

#include "components/camera_2d_component.h"
#include "rendering/sprite_quad_vertex_data.h"
#include "components/graphics_component.h"

class RenderingSystem {
private:
	std::set<GraphicsComponent*> _drawTargets;

	Camera2DComponent* _activeCamera;

	SpriteQuadVertexData _spriteQuadVertexData;
public:
	
	RenderingSystem();

	void setActiveCamera(Camera2DComponent* camera);
	void addDrawTarget(GraphicsComponent* target);
	void removeDrawTarget(GraphicsComponent* target);

	void clear() const;
	void draw() const;
};
