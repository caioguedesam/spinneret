#pragma once

#include <set>

#include "components/camera_2d_component.h"
#include "rendering/sprite_quad_vertex_data.h"
#include "components/graphics_component.h"

class RenderingSystem
{
private:
	std::set<GraphicsComponent*> _drawTargets;
	Camera2DComponent* _activeCamera;

	SpriteQuadVertexData _spriteQuadVertexData;

	static RenderingSystem& getInstance()
	{
		static RenderingSystem instance;
		return instance;
	}

public:
	static void init();

	static void setActiveCamera(Camera2DComponent* camera);
	static void addDrawTarget(GraphicsComponent* target);
	static void removeDrawTarget(GraphicsComponent* target);

	static void clear();
	static void draw();
};
