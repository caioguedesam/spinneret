#pragma once

#include <SDL.h>

class TimeSystem
{
private:
	static double _time;
	static double _deltaTime;
	static double _fixedDeltaTime;

	inline static double getTicksInSeconds(Uint32 ticks) { return 1.e-3 * (double)ticks; }
public:
	static void init();
	static void updateTime();

	inline static double getTime() { return _time; }
	inline static double getDeltaTime() { return _deltaTime; }
};