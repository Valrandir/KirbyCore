#pragma once
#include <Core.h>
#include "../IRender.h"

using namespace Core::Window;

class Field;

class DebugRender : public IRender
{
	WindowGDI* pWindowGDI;

	public:
	void Create();
	void Activate();
	unsigned int Refresh();
	~DebugRender();
	void RenderWorld(World const * pWorld);

	private:
	void RenderScore(int score);
	void RenderField(Field const * pField);
};
