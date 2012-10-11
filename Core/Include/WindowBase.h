#pragma once
#include "String.h"

namespace Core
{
	class __declspec(dllexport) WindowBase
	{
		public:
		virtual ~WindowBase() = 0;
		virtual void Show() const = 0;
		virtual bool Update() const = 0;
		virtual void GetSize(int& width, int& height) const = 0;
		virtual void GetClientSize(int& clientWidth, int& clientHeight) const = 0;

		static WindowBase* Create(CORECSTR title, int clientWidth, int clientHeight);
	};
}
