#include <Core.h>
#include "BlockMkr.h"

/*
unsigned int BlockMkr::vColor[nColor] =
{
	0x0000ff, //Red
	0x00ff00, //Green
	0xff0000, //Blue
	0x00ffff, //Yellow
	0xD000D0, //Purple
};
*/

unsigned int BlockMkr::vColor[nColor] =
{
	0xC0C0C0, //Even Less Gray
	0xA0A0A0, //Less Gray
	0x808080, //Gray
	0x606060, //More Gray
	0x404040, //Even More Gray
};

unsigned int BlockMkr::GetRandomBlock()
{
	int idx = Core::Random::Rnd(0, nColor - 1);
	return vColor[idx];
}
