#pragma once

#include <set>

#include "renderer/renderable/renderable.h"
#include "renderer/renderable/sprite_renderable.h"

class Renderer {
private:
	std::set<Renderable*> _renderables;

	SpriteRenderableVertexData _spriteRenderableVertexData;
public:
	
	Renderer();

	void addRenderable(Renderable& renderable);
	void removeRenderable(Renderable& renderable);

	void clear() const;
	void draw() const;
};
