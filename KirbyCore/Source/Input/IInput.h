#pragma once

enum CommandEnum
{
	CmdNone = 0x0,
	CmdMoveUp = 0x1,
	CmdMoveDown = 0x2,
	CmdMoveLeft = 0x4,
	CmdMoveRight = 0x8,
	CmdActionB = 0x10,
	CmdActionA = 0x20,
	CmdActionY = 0x40,
	CmdActionX = 0x80,
	CmdActionL = 0x100,
	CmdActionR = 0x200
};

class IInput
{
	public:
	static IInput* Create();
	virtual ~IInput();
	virtual void Read(unsigned int ModelTick) = 0;
	virtual unsigned int Peek(CommandEnum command) = 0;
};
