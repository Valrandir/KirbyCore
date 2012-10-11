#pragma once
#include "String.h"

using namespace Core;

class StringImpl : public String
{
	CORESTR ptr;

	public:
	StringImpl(CORESTR ptr);
	int GetChrCount() const;
	int GetByteSize() const;
};
