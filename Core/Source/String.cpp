#include "../Include/String.h"
#include "../Include/StringImpl.h"
using namespace Core;

String::~String()
{
}

String* String::Create(CORESTR ptr)
{
	return new StringImpl(ptr);
}
