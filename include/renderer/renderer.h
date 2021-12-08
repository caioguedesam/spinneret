#pragma once

#include <set>

#include "camera/camera_2d.h"
#include "renderer/renderable/sprite_renderable_vertex_data.h"
#include "component_system/components/graphics_component.h"

class Renderer {
private:
	std::set<GraphicsComponent*> _drawTargets;

	Camera2D* _camera;

	SpriteRenderableVertexData _spriteQuadVertexData;
public:
	
	Renderer();

	void setCamera(Camera2D& camera);
	void addDrawTarget(GraphicsComponent* target);
	void removeDrawTarget(GraphicsComponent* target);

	void clear() const;
	void draw() const;
};
