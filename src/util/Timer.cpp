#include "Timer.h"

Timer::Timer() {
	start();
}

void Timer::start() {
	m_lastFrame = SDL_GetTicks();
}

Uint32 Timer::reset() {
	Uint32 time = SDL_GetTicks();
	Uint32 ret = get();
	start();
	return ret;
}

Uint32 Timer::get() {
	return SDL_GetTicks() - m_lastFrame;
}

void Timer::wait(Uint32 msec) {
	start();
	while (get() < msec) {}
}