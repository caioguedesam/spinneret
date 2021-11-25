#pragma once

#include <set>

#include "renderer/renderable/renderable.h"
#include "renderer/renderable/sprite_renderable.h"
#include "mat4x4.hpp"

class Renderer {
private:
	std::set<Renderable*> _renderables;

	glm::mat4 _view;
	glm::mat4 _perspective;

	SpriteRenderableVertexData _spriteRenderableVertexData;
public:
	
	Renderer();

	void setViewMatrix(const glm::mat4 view);
	void setPerspectiveMatrix(const float& left, const float& right, const float& bottom, const float& top,
		const float& near, const float& far);
	
	void addRenderable(Renderable& renderable);
	void removeRenderable(Renderable& renderable);

	void clear() const;
	void draw() const;

	inline glm::mat4 getViewMatrix() const { return _view; }
	inline glm::mat4 getPerspectiveMatrix() const { return _perspective; }
};
