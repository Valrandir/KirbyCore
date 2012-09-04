#include "HighPerfTick.h"
#include "TickRate.h"

using namespace Core::Time;

TickRate::TickRate()
{
	Initialise(60, 1.0L);
}

TickRate::TickRate(unsigned int updatesPerSec, double rate)
{
	Initialise(updatesPerSec, rate);
}

void TickRate::Initialise(unsigned int updatesPerSec, double rate)
{
	this->updatesPerSec = updatesPerSec;
	this->rate = rate;
	msPerUpdate = 1000.0L / updatesPerSec / rate;
	mod = 0.0L;
}

void TickRate::Reset()
{
	mod = 0.0L;
	timer.Reset();
}

unsigned int TickRate::TickUpdate()
{
	unsigned int tick;
	double rawUpdateCount;
	int updateCount;

	tick = timer.Tick();
	rawUpdateCount = tick / msPerUpdate;
	rawUpdateCount += mod;
	updateCount = (int)rawUpdateCount;
	mod = rawUpdateCount - updateCount;

	return updateCount;
}

unsigned int TickRate::GetUpdatesPerSec() const
{
	return updatesPerSec;
}

double TickRate::GetRate() const
{
	return rate;
}
