#include "entity/scene.h"

Scene::~Scene()
{
	for (auto& entity : _entities)
	{
		delete entity;
	}
}

void Scene::addEntity(Entity* entity)
{
	_entities.insert(entity);
}

void Scene::removeEntity(Entity* entity)
{
	_entities.erase(entity);
}
