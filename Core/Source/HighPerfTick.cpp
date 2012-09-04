#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "HighPerfTick.h"

__int64 HighPerfTick::GetFrequency()
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	return frequency.QuadPart / 1000U;
}

__int64 HighPerfTick::GetCounter()
{
	LARGE_INTEGER performanceCount;
	QueryPerformanceCounter(&performanceCount);
	return performanceCount.QuadPart / frequency;
}

HighPerfTick::HighPerfTick()
{
	frequency = GetFrequency();
	Reset();
}

void HighPerfTick::Reset()
{
	lastTick = GetCounter();
}

unsigned int HighPerfTick::Tick()
{
	__int64 counter = GetCounter();
	unsigned int elapsed = (unsigned int)(counter - lastTick);
	lastTick = counter;
	return elapsed;
}
