#pragma once

namespace Core
{
	#ifdef UNICODE
		//typedef wchar_t CORECHAR;
		typedef wchar_t const * CORESTR;
	#else
		typedef char const * CORESTR;
	#endif

	class String
	{
		public:
		virtual ~String() = 0;
		virtual int GetChrCount() const = 0;
		virtual int GetByteSize() const = 0;

		static String* Create(CORESTR ptr);
	};
}
