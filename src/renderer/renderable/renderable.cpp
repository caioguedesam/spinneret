#include "renderer/renderable/renderable.h"
#include "renderer/renderer.h"

void Renderable::bind(Renderer* renderer)
{
	_renderer = renderer;
}

glm::mat4 Renderable::getMVP() const
{
	// TODO: replace with actual model value
	return _renderer->getPerspectiveMatrix() * _renderer->getViewMatrix() * glm::mat4(1.f);
}
