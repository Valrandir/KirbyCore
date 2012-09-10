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
	if(GetAsyncKeyState('B')) bitFlag |= CmdActionB;
	if(GetAsyncKeyState('A')) bitFlag |= CmdActionA;
	if(GetAsyncKeyState('Y')) bitFlag |= CmdActionY;
	if(GetAsyncKeyState('X')) bitFlag |= CmdActionX;
	if(GetAsyncKeyState('L')) bitFlag |= CmdActionL;
	if(GetAsyncKeyState('R')) bitFlag |= CmdActionR;
}

unsigned int DebugInput::Peek(CommandEnum command)
{
	return bitFlag & command;
}
