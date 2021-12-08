#pragma once

#include "entity/entity.h"

#include <set>

class Scene
{
private:
	std::set<Entity*> _entities;
public:
	~Scene();

	void addEntity(Entity* entity);
	void removeEntity(Entity* entity);

	inline const std::set<Entity*>& entities() const { return _entities; }
};
