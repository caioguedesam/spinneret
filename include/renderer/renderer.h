#pragma once

#include <set>

#include "renderer/renderable/renderable.h"

class Renderer {
private:
	std::set<Renderable*> _renderables;
public:
	void init() const;

	void addRenderable(Renderable& renderable);
	void removeRenderable(Renderable& renderable);

	void clear() const;
	void draw() const;
};
