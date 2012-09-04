#pragma once
#include "HighPerfTick.h"

namespace Core { namespace Time {

class TickRate
{
	protected:
	HighPerfTick timer;
	unsigned int updatesPerSec;
	double rate;
	double msPerUpdate;
	double mod;

	public:
	TickRate();
	TickRate(unsigned int updatesPerSec, double rate);
	void Initialise(unsigned int updatesPerSec, double rate);
	void Reset();
	unsigned int TickUpdate();

	unsigned int GetUpdatesPerSec() const;
	double GetRate() const;
};

} }
