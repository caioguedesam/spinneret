#pragma once

#include <SDL.h>
#include <unordered_map>
#include <list>

class EventSystem
{
private:
	std::unordered_map<Uint32, std::list<void(*)()>> _callbacks;

	static EventSystem& getInstance()
	{
		static EventSystem instance;
		return instance;
	}
public:
	static void addCallback(Uint32 type, void(*callback)());
	static void removeCallback(Uint32 type, void(*callback)());
	static void pollEvents();
};