#pragma once

#include "components/component.h"
#include <SDL.h>

class TestComponent : public Component
{
private:
	int _respondCount;
public:
	TestComponent();

	void update(double dt) override;

	void raiseTestEvent(SDL_Event event);
	void respondToTestEvent(SDL_Event event);
};
