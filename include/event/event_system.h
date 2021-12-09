#pragma once

#include <SDL.h>
#include <unordered_map>
#include <list>
#include <functional>

#include "components/component.h"

class EventSystem
{
private:
	std::unordered_map<Uint32, std::list<std::function<void(SDL_Event)>>> _callbacks;

	static EventSystem& getInstance()
	{
		static EventSystem instance;
		return instance;
	}
public:
	static void addCallback(Uint32 type, std::function<void(SDL_Event)> callback);
	static void removeCallback(Uint32 type, std::function<void(SDL_Event)> callback);
	static void pollEvents();
};