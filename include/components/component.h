#pragma once

class Entity;

class Component
{
protected:
	Entity* _entity;
public:
	virtual ~Component() {};

	void bindToEntity(Entity* entity);
	inline Entity* getEntity() const { return _entity; }

	virtual void update(double dt);
};
