#include "renderer/renderable/renderable.h"
#include "renderer/renderer.h"
#include "resource_loader/resource_loader.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

void Renderable::bind(Renderer* renderer)
{
	_renderer = renderer;
}

void Renderable::setShader(const std::string& shaderName)
{
	Shader* shader = ResourceLoader::getShader(shaderName);
	if (shader == nullptr) {
		logError("RENDERABLE", "Could not load shader " + shaderName + " from resources");
		return;
	}
	_shader = shader;
}

void Renderable::sendMVPUniform(const glm::mat4& view_projection_matrix)
{
	// TODO: Replace identity temp with _model matrix
	glm::mat4 mvp = view_projection_matrix * glm::mat4(1.f);
	_shader->setMat4("u_mvp", mvp);
}
