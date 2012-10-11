#include "../Include/Window2D.h"
#include "../Include/Window2DImpl.h"
using namespace Core;

Window2D::~Window2D()
{
}

Window2D* Window2D::Create(CORESTR title, int clientWidth, int clientHeight)
{
	return new Window2DImpl(title, clientWidth, clientHeight);
}
