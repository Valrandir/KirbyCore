#pragma once
#include "../IInput.h"

class DebugInput : public IInput
{
	unsigned int bitFlag;

	public:
	~DebugInput();
	void Read(unsigned int ModelTick);
	unsigned int Peek(CommandEnum command);
};
