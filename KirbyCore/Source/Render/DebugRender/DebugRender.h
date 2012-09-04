#pragma once
#include <Core.h>
#include "../IRender.h"

using namespace Core::Window;

class DebugRender : public IRender
{
	WindowGDI* pWindowGDI;

	public:
	void Create();
	void Activate();
	unsigned int Refresh();
	~DebugRender();
	void RenderField(Field const * pField);
};
