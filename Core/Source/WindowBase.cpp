#include "../Include/WindowBase.h"
#include "../Include/WindowBaseImpl.h"
using namespace Core;

WindowBase::~WindowBase()
{
	PostQuitMessage(0);
}

WindowBase* WindowBase::Create(CORECSTR title, int clientWidth, int clientHeight)
{
	return new WindowBaseImpl(title, clientWidth, clientHeight);
}
