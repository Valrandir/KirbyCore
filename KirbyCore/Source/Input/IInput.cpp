#include "IInput.h"
#include "DebugInput/DebugInput.h"

IInput* IInput::Create()
{
	return new DebugInput();
}

IInput::~IInput() {}
