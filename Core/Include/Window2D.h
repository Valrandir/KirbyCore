#pragma once
#include "WindowBase.h"

namespace Core
{
	class __declspec(dllexport) Window2D : public WindowBase
	{
		public:
		virtual ~Window2D() = 0;
		virtual void Clear() const = 0;
		virtual void DrawRect(int x, int y, int width, int height, unsigned int color) const = 0;
		virtual void DrawLine(int x, int y, int x2, int y2) const = 0;
		//virtual void DrawText(CORESTR text, int len, int x, int y) const = 0;

		static Window2D* Create(CORESTR title, int clientWidth, int clientHeight);
	};
}
