#include "time/time_system.h"

double TimeSystem::_time;
double TimeSystem::_deltaTime;
double TimeSystem::_fixedDeltaTime;

void TimeSystem::init()
{
	_time = getTicksInSeconds(SDL_GetTicks());
	_deltaTime = 0.;
	_fixedDeltaTime = 0.02;
}

void TimeSystem::updateTime()
{
	double currentTime = getTicksInSeconds(SDL_GetTicks());
	_deltaTime = currentTime - _time;
	_time = currentTime;
}
