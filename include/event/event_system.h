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

	static Uint32 _gameEventType;
	static EventSystem& getInstance()
	{
		static EventSystem instance;
		return instance;
	}
public:
	static void init();

	static void pollEvents();
	static void raiseEvent(const Sint32& eventCode, void* eventData);

	static void addCallback(Uint32 type, void (*callback)(SDL_Event));
	template<typename T>
	static void addCallback(Uint32 type, T* caller, void (T::*callback)(SDL_Event))
	{
		auto bindCallback = std::bind(callback, caller, std::placeholders::_1);
		getInstance()._callbacks[type].push_back(bindCallback);
	}

	inline static const Uint32 getGameEventType() { return _gameEventType; }
};