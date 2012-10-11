#pragma once

namespace Core
{
	#ifdef UNICODE
		typedef wchar_t const * CORESTR;
	#else
		typedef char const * CORESTR;
	#endif
}
