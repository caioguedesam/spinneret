#pragma once

class Entity;

class Component
{
protected:
	Entity* _entity;
public:
	Component(Entity* entity);
	virtual ~Component() {};

	inline Entity* getEntity() const { return _entity; }

	// TODO: Implement component Update (and OnLoad?)
};
