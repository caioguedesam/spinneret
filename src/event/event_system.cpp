#include "event/event_system.h"
#include "logs.h"

Uint32 EventSystem::_gameEventType;

void EventSystem::init()
{
	_gameEventType = SDL_RegisterEvents(1);
	if (_gameEventType == ((Uint32)-1))
		logError("EVENT_SYSTEM", "Couldn't initialize custom game event type in Event System.");
}

void EventSystem::pollEvents()
{
	EventSystem& instance = getInstance();
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		Uint32 type = event.type;
		std::list<std::function<void(SDL_Event)>> callbacks = instance._callbacks[type];
		for (auto& callback : callbacks)
		{
			callback(event);
		}
	}
}

void EventSystem::raiseEvent(const Sint32& eventCode, void* eventData)
{
	SDL_Event event;
	SDL_memset(&event, 0, sizeof(event));
	event.type = _gameEventType;
	event.user.code = eventCode;
	event.user.data1 = eventData;
	SDL_PushEvent(&event);
}

void EventSystem::addCallback(Uint32 type, void(*callback)(SDL_Event))
{
	auto bindCallback = std::bind(callback, std::placeholders::_1);
	getInstance()._callbacks[type].push_back(bindCallback);
}
