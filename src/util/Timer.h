#pragma once
#include <SDL.h>

class Timer {
protected:
	Uint32 m_lastFrame;
public:
	Timer();
	void start();
	Uint32 reset();
	Uint32 get();
	void wait(Uint32 msec);
};