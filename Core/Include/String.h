#pragma once

namespace Core
{
	#ifdef UNICODE
		#define CORETEXT(quote)L##quote
		typedef wchar_t CORECHAR;
		typedef wchar_t const* CORECSTR;
		typedef wchar_t* CORESTR;
	#else
		#define CORETEXT(quote)quote
		typedef char CORECHAR;
		typedef char const* CORECSTR;
		typedef char* CORESTR;
	#endif

	class String
	{
		public:
		static int GetLength(CORECSTR text);
		static void Format(CORESTR buffer, int bufferSize, CORECSTR format, ...);
	};
}
