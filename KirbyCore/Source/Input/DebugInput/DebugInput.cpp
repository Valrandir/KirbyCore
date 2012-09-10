#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "DebugInput.h"

DebugInput::~DebugInput()
{
}

void DebugInput::Read(unsigned int ModelTick)
{
	bitFlag = CmdNone;

	if(GetAsyncKeyState(VK_UP)) bitFlag |= CmdMoveUp;
	if(GetAsyncKeyState(VK_DOWN)) bitFlag |= CmdMoveDown;
	if(GetAsyncKeyState(VK_LEFT)) bitFlag |= CmdMoveLeft;
	if(GetAsyncKeyState(VK_RIGHT)) bitFlag |= CmdMoveRight;
	if(GetAsyncKeyState('D')) bitFlag |= CmdActionB;
	if(GetAsyncKeyState('F')) bitFlag |= CmdActionA;
	if(GetAsyncKeyState('E')) bitFlag |= CmdActionY;
	if(GetAsyncKeyState('R')) bitFlag |= CmdActionX;
	if(GetAsyncKeyState('Q')) bitFlag |= CmdActionL;
	if(GetAsyncKeyState('W')) bitFlag |= CmdActionR;
}

unsigned int DebugInput::Peek(CommandEnum command)
{
	return bitFlag & command;
}
