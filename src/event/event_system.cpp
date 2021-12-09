#include "event/event_system.h"

void EventSystem::addCallback(Uint32 type, void(*callback)())
{
	getInstance()._callbacks[type].push_back(callback);
}

void EventSystem::removeCallback(Uint32 type, void(*callback)())
{
	getInstance()._callbacks[type].remove(callback);
}

void EventSystem::pollEvents()
{
	EventSystem& instance = getInstance();
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		Uint32 type = event.type;
		std::list<void(*)()> callbacks = instance._callbacks[type];
		for (auto& callback : callbacks)
		{
			callback();
		}
	}
}
