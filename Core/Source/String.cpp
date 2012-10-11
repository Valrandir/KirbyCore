#include <stdio.h>
#include <stdarg.h>
#include <tchar.h>
#include "../Include/String.h"

using namespace Core;

void String::Format(CORESTR buffer, int bufferSize, CORECSTR format, ...)
{
	va_list ap;
	va_start(ap, format);
	_vsntprintf_s(buffer, bufferSize, _TRUNCATE, format, ap);
	va_end(ap);
}
