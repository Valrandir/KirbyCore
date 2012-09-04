#include "IRender.h"
#include "DebugRender/DebugRender.h"

IRender* IRender::Create()
{
	return new DebugRender();
}

IRender::~IRender() {}
