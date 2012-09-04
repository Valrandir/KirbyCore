#pragma once

class HighPerfTick
{
	__int64 frequency;
	__int64 lastTick;
	__int64 GetFrequency();
	__int64 GetCounter();

	public:
	HighPerfTick();
	void Reset();
	unsigned int Tick();
};
