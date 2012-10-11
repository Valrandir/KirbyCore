#pragma once
#include <Core.h>
#include "../IRender.h"

class Field;

class DebugRender : public IRender
{
	Core::Window2D* pWindow2D;

	public:
	void Activate();
	unsigned int Refresh();
	~DebugRender();
	void RenderWorld(World const * pWorld);

	private:
	void RenderScore(int score);
	void RenderField(Field const * pField);
};
