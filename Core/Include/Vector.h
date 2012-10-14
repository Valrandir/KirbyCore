#pragma once

namespace Core
{
	template<class T> class Vector
	{
		public:
		virtual ~Vector() = 0;
		virtual void Reserve(int size) = 0;
		virtual void Push(T val) = 0;
		virtual void Pop() = 0;
		virtual void Clear() = 0;
		virtual T* Begin() = 0;
		virtual T* End() = 0;
		virtual int Length() const = 0;

		static Vector<T>* Create();
	};
}
