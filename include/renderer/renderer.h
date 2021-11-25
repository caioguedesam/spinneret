#pragma once

#include <set>

#include "camera/camera_2d.h"
#include "renderer/renderable/renderable.h"
#include "renderer/renderable/sprite_renderable_vertex_data.h"

class Renderer {
private:
	std::set<Renderable*> _renderables;

	Camera2D* _camera;

	SpriteRenderableVertexData _spriteRenderableVertexData;
public:
	
	Renderer();

	void setCamera(Camera2D& camera);
	void addRenderable(Renderable& renderable);
	void removeRenderable(Renderable& renderable);

	void clear() const;
	void draw() const;
};
